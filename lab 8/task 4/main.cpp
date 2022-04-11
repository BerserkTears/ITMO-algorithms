#include <fstream>
#include <vector>

using namespace std;

void Dfs(int node, int component, vector<vector<int>> &list, vector<int> &colors) {
    colors[node] = component;
    for (int i = 0; i < list[node].size(); i++) {
        if (colors[list[node][i]] == 0)
            Dfs(list[node][i], component, list, colors);
    }
}

int main() {
    ifstream fin("components.in");
    ofstream fout("components.out");
//    ifstream fin("input.txt");
//    ofstream fout("output.txt");
    int n, m;
    fin >> n >> m;
    vector<vector<int>> list(n, vector<int>());
    vector<int> colors(n, 0);
    for (int i = 0; i < m; ++i) {
        int j, k;
        fin >> j >> k;
        list[j - 1].push_back(k - 1);
        list[k - 1].push_back(j - 1);
    }
    int components = 0;
    for (int i = 0; i < n; i++) {
        if (colors[i] == 0) {
            components++;
            Dfs(i, components, list, colors);
        }
    }
    fout << components << endl;
    for (int color: colors) {
        fout << color << " ";
    }
    fout.close();
    return 0;
}