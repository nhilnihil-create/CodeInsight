#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){ return v2<T>(r, vector<T>(c, t)); }
#define F first
#define S second

void solve(){
    int n;
    string s, t;
    cin >> n >> s >> t;
    for(int i = 0; i < n; ++i){
        string s1 = s.substr(i), s2 = t.substr(0,n-i);
        if(s1==s2){
            cout << n+i << '\n';
            return;
        }
    }
    cout << 2*n << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}