#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n, m;
    fin >> n >> m;
    vector<vector<int>> matrix(n,vector<int>(n ,0));
    for (int i = 0; i < m; ++i) {
        int j,k;
        fin >> j >> k;
        if (matrix[k - 1][j - 1] == 1) {
            fout << "YES";
            fout.close();
            return 0;
        }
        matrix[j - 1][k - 1] = 1;
        matrix[k - 1][j - 1] = 1;
    }
    fout << "NO";
    fout.close();
    return 0;
}