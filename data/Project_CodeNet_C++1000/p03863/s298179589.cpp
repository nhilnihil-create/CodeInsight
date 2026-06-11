#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

int main(){
    string s;
    cin >> s;
    int n = s.size();

    bool flag = true;
    set<char> st;
    for(int i=1; i<n-1; i++){
        if(s[i-1] != s[i+1]) flag = false;
    }
    rep(i, n) st.insert(s[i]);

    if(st.size() == 2 && flag){
        cout << "Second" << endl;
        return 0;
    }

    if(s[0] == s[n-1]){
        if((n-2)%2 == 0) cout << "First" << endl;
        else cout << "Second" << endl;
    }
    else if((n-2)%2 == 0) cout << "Second" << endl;
    else cout << "First" << endl;
}