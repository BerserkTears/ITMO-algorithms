#include <fstream>
#include "vector"

using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n, m;
    fin >> n >> m;
    vector<vector<unsigned int>> board(n, vector<unsigned int>(m, 0));
    board[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if ()
        }
    }
    fout.close();
    return 0;
}