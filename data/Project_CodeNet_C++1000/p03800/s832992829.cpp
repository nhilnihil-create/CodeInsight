#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main(){
    int n; cin >> n;
    string s; cin >> s;
    vector<int> ans(n,0);
    
    ans[0] = 1; ans[1] = 1;
    loop(i,1,n-1){
        if((s[i] == 'o' && ans[i] == 1) || (s[i] == 'x' && ans[i] == -1)) ans[i+1] = ans[i-1];
        else ans[i+1] = ans[i-1]*(-1);
    }
    if((s[0] == 'o' && ans[n-1]*ans[0]*ans[1] == 1) || (s[0] == 'x' && ans[n-1]*ans[0]*ans[1] == -1)){
       if((s[n-1] == 'o' && ans[n-2]*ans[n-1]*ans[0] == 1) || (s[n-1] == 'x' && ans[n-2]*ans[n-1]*ans[0] == -1)){
           string res = "";
           rep(i,n){ if(ans[i] == 1) res += "S"; else res += "W"; }
           cout << res << endl; return 0;
        }
    }
    ans[0] = 1; ans[1] = -1;
    loop(i,1,n-1){
        if((s[i] == 'o' && ans[i] == 1) || (s[i] == 'x' && ans[i] == -1)) ans[i+1] = ans[i-1];
        else ans[i+1] = ans[i-1]*(-1);
    }
    if((s[0] == 'o' && ans[n-1]*ans[0]*ans[1] == 1) || (s[0] == 'x' && ans[n-1]*ans[0]*ans[1] == -1)){
       if((s[n-1] == 'o' && ans[n-2]*ans[n-1]*ans[0] == 1) || (s[n-1] == 'x' && ans[n-2]*ans[n-1]*ans[0] == -1)){
           string res = "";
           rep(i,n){ if(ans[i] == 1) res += "S"; else res += "W"; }
           cout << res << endl; return 0;
        }
    }
    ans[0] = -1; ans[1] = 1;
    loop(i,1,n-1){
        if((s[i] == 'o' && ans[i] == 1) || (s[i] == 'x' && ans[i] == -1)) ans[i+1] = ans[i-1];
        else ans[i+1] = ans[i-1]*(-1);
    }
    if((s[0] == 'o' && ans[n-1]*ans[0]*ans[1] == 1) || (s[0] == 'x' && ans[n-1]*ans[0]*ans[1] == -1)){
       if((s[n-1] == 'o' && ans[n-2]*ans[n-1]*ans[0] == 1) || (s[n-1] == 'x' && ans[n-2]*ans[n-1]*ans[0] == -1)){
           string res = "";
           rep(i,n){ if(ans[i] == 1) res += "S"; else res += "W"; }
           cout << res << endl; return 0;
        }
    }
    ans[0] = -1; ans[1] = -1;
    loop(i,1,n-1){
        if((s[i] == 'o' && ans[i] == 1) || (s[i] == 'x' && ans[i] == -1)) ans[i+1] = ans[i-1];
        else ans[i+1] = ans[i-1]*(-1);
    }
    if((s[0] == 'o' && ans[n-1]*ans[0]*ans[1] == 1) || (s[0] == 'x' && ans[n-1]*ans[0]*ans[1] == -1)){
       if((s[n-1] == 'o' && ans[n-2]*ans[n-1]*ans[0] == 1) || (s[n-1] == 'x' && ans[n-2]*ans[n-1]*ans[0] == -1)){
           string res = "";
           rep(i,n){ if(ans[i] == 1) res += "S"; else res += "W"; }
           cout << res << endl; return 0;
        }
    }
    cout << -1 << endl; return 0;
}