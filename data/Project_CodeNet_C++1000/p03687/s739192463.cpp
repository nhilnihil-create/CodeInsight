#include <bits/stdc++.h>
using namespace std;

int simulate(string S, char ch)
{
    int res = 0;
    //cout << "ch:" << ch << endl;
    //cout << S << endl;
    if(S.find(ch) == S.npos) { return 1000000; }
    do {
        bool flg = true;
        for(size_t i = 0; i < S.size()-1; ++i) {
            if(S[i] != ch && S[i+1] == ch) flg = false, S[i] = ch;
        }
        if(S.back() != ch) flg = false;
        if(flg) break;
        S.erase(S.end()-1);
        ++res;
        //cout << S << endl;
    } while(true);
    //cout << endl;
    return res;
}

int main() {
    string S;
    cin >> S;
    int res = 1000000;
    for(char ch = 'a'; ch <= 'z'; ++ch) {
        res = min(res, simulate(S,ch));
    }
    cout << res << endl;
    return 0;
}