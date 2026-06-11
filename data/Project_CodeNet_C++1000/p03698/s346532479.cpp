#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
using namespace std;
typedef vector<int> vi;

int main(){
    string S;
    set<char> tmp;
    cin >> S;

    bool ok = true;
    rep(i, S.size()){
        tmp.insert(S[i]);
    }

    if(S.size() != tmp.size()) ok = false;

    if(ok) cout << "yes" << endl;
    else cout << "no" << endl;

    return 0;
}