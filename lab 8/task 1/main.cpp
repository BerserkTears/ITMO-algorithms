#include <fstream>
#include <vector>

using namespace std;

int main() {
    ofstream fout("output.txt");
    ifstream fin("input.txt");
    int n, m;
    fin >> n >> m;
    vector<vector<int>> ribs(n + 1,vector<int>(n + 1, 0));
    for (int i = 0; i < m; ++i) {
        int j, k;
        fin >> j >> k;
        ribs[j][k] = 1;
    }
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            fout << ribs[i][j] << " ";
        }
        fout << endl;
    }
    return 0;
}
