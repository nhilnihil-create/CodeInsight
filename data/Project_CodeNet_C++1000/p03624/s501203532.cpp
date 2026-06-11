#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, N) for (int i = 0; i < (int)(N); i++)

// chmax, chmin
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    string S;
    cin >> S;
    
    vector<int> v(26,0);
    
    REP(i,S.size()){
        v[S[i]-'a'] = 1;
    }
    
    REP(i,26){
        //cout << v[i] << endl;
        if ( v[i] == 0 ) {
            char x = i + 'a';
            cout << x << endl;
            return 0;
        }
    }
    cout << "None" << endl;
    
    
    return 0;
}
