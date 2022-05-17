#include "vector"
#include "iostream"

using namespace std;

int main(){
    int n, mx = 0;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            if (a[i-1][j] != 0 && a[i][j - 1] != 0 && a[i][j] != 0 && a[i - 1][j - 1] != 0)
                a[i][j] = a[i - 1][j - 1] + 1;
            if (a[i][j] > mx)
                mx = a[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << mx;
}