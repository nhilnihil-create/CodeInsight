#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x ,n) for(int i = x; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main(){
    int n,l;
    string s[110];
    cin >> n >> l;
    
    rep(i,n)cin >> s[i];
    sort(s,s+n);
    
    rep(i,n)cout << s[i];
    cout << endl;
    
    return 0;
}