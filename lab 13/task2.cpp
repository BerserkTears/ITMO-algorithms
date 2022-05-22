#include "fstream"
#include "vector"

using namespace std;

vector<int> prefixFunction(string &s){
    vector<int> p(s.length());
    p[0] = 0;
    for (int i = 1; i < s.length(); ++i) {
        int k = p[i - 1];
        while(k > 0 && s[i] != s[k])
            k = p[k - 1];
        if (s[i] == s[k])
            k++;
        p[i] = k;
    }
    return p;
}

vector<int> search(string &P, string &T){
    vector<int> answer;
    int pl = (int)P.length();
    int tl = (int)T.length();
    string S = P + "#" + T;
    vector<int> p = prefixFunction(S);
    for (int i = 0; i < tl; ++i) {
        if (p[pl + i + 1] == pl)
            answer.push_back(i - pl + 2);
    }
    return answer;
}

#ifndef TESTING

int main(){
    ifstream fin("search2.in");
    ofstream fout("search2.out");
    string a,b;
    fin >> a >> b;
    vector<int> result = search(a,b);
    fout << result.size() << endl;
    for (int num : result){
        fout << num << " ";
    }
    fout.close();
    return 0;
}
#endif