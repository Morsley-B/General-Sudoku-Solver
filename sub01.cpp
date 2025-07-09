#include <iostream>
#include <vector>
#include <sstream>
#include <forward_list>
#include <cmath>

using namespace std;

int gridSize = 9;
vector<vector<int>> grid;
forward_list<int> solution;
bool isSolved = false;

class Sudoku {
private:
    class header;
    class node {
    public:
        int row;
        header* head;
        node* up, * down, * left, * right;
    };

    class header : public node {
    public:
        int count;
        header* left, * right;
    };

    int n, numRows, numCols;
    header* rootNode;
    vector<vector<node>> rows;
    vector<header> cols;

public:
    Sudoku() {
        n = gridSize;
        numCols = (n * n * 4) + 1;
        numRows = n * n * n;

        rows = vector<vector<node>>(numRows, vector<node>(4, node()));
        cols = vector<header>(numCols, header());

        rootNode = &(cols[numCols - 1]);

        for (int i = 0; i < numCols; i++) {
            cols[i].up = &cols[i];
            cols[i].down = &cols[i];
            cols[i].left = &(cols[(i + numCols - 1) % numCols]);
            cols[i].right = &(cols[(i + 1) % numCols]);
            cols[i].count = 0;
        }

        int n2 = n * n;
        int boxWidth = sqrt(n);

        for (int r = 0; r < numRows; r++) {
            int colInd, currRow = r / (n * n), currCol = (r / n) % n, offset = r % n;

            if (grid[currRow][currCol] != 0 && grid[currRow][currCol] != offset + 1) continue;

            for (int c = 0; c < 4; c++) {
                int colStart = c * n2;
                switch (c) {
                case 0:
                    colInd = r / n;
                    break;
                case 1:
                    colInd = n2 + (currRow * n) + offset;
                    break;
                case 2:
                    colInd = colStart + ((r / n) % n) * n + offset;
                    break;
                case 3:
                    colInd = colStart + (boxWidth * (currRow / boxWidth) + (currCol / boxWidth)) * n + offset;
                    break;
                }
                rows[r][c].row = r;
                rows[r][c].down = &cols[colInd];
                rows[r][c].right = &(rows[r][(c + 1) % 4]);
                rows[r][c].left = &(rows[r][(c + 3) % 4]);
                rows[r][c].up = cols[colInd].up;
                rows[r][c].head = &cols[colInd];
                rows[r][c].up->down = &rows[r][c];
                rows[r][c].down = &cols[colInd];
                cols[colInd].up->down = &(rows[r][c]);
                cols[colInd].up = &(rows[r][c]);
                cols[colInd].count++;
            }
        }
    }

    void print() {
        int currRow, currCol, offset;

        for (int &r : solution) {
            currRow = r / (n * n);
            currCol = (r / n) % n;
            offset = r % n + 1;
            grid[currRow][currCol] = offset;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] >= 10) cout << char(grid[i][j] + 55);
                else cout << grid[i][j];
                if (j != n - 1) cout << " ";
            }
            cout << endl;
        }
    }

    void solve() {
        if (rootNode->right == rootNode) {
            isSolved = true;
            print();
            return;
        }

        header* bestCol = rootNode->right;

        for (header* c = rootNode->right; c != rootNode; c = c->right) {
            if (c->count < bestCol->count) bestCol = c;
        }

        cover(bestCol);

        for (node* currRow = bestCol->down; currRow != bestCol; currRow = currRow->down) {
            solution.push_front(currRow->row);

            for (node* currCol = currRow->right; currCol != currRow; currCol = currCol->right) cover(currCol->head);

            solve();
            solution.pop_front();

            for (node* currCol = currRow->left; currCol != currRow; currCol = currCol->left) uncover(currCol->head);
        }

        uncover(bestCol);
    }

private:
    void cover(header* col) {
        col->right->left = col->left;
        col->left->right = col->right;

        for (node* r = col->down; r != col; r = r->down) {
            for (node* c = r->right; c != r; c = c->right) {
                c->up->down = c->down;
                c->down->up = c->up;
                c->head->count--;
            }
        }
    }

    void uncover(header* col) {
        for (node* r = col->up; r != col; r = r->up) {
            for (node* c = r->left; c != r; c = c->left) {
                c->up->down = c;
                c->down->up = c;
                c->head->count++;
            }
        }

        col->right->left = col;
        col->left->right = col;
    }
};

int main() {
    string inp;
    while (getline(cin, inp)) {
        stringstream currStr(inp);
        vector<int> numbers;
        string curr;
        while (getline(currStr, curr, ' ')) {
            if (int(curr[0]) >= 65 && int(curr[0]) <= 90) numbers.push_back(curr[0] - 55);
            else numbers.push_back(stoi(curr));
        }
        grid.push_back(numbers);
    }

    gridSize = grid.size();
    Sudoku sudGrid;
    sudGrid.solve();

    if (!isSolved) cout << "No Solution" << endl;

    return 0;
}
