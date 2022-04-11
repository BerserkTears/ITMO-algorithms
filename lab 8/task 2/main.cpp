#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n;
    fin >> n;
    vector<vector<int>> ribs (n, vector<int>(n,0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            fin >> ribs[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (ribs[i][j] != ribs[j][i]) {
                fout << "NO";
                fout.close();
                return 0;
            }
        }
        if (ribs[i][i] == 1){
            fout << "NO";
            fout.close();
            return 0;
        }
    }
    fout <<  "YES";
    fout.close();
    return 0;
}