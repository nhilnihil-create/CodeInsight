#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "O3"
#define rep(i,a,n) for(long long i=a; i<n; i++)
typedef long long ll;
typedef pair<int,int> P;
const ll MOD = (int)1e9+7;
const ll INF = MOD*MOD;
const double EPS = 1e-9;
const ll powll = 1LL<<1;

/*
while(!frag && cin >> a >>b, a|b)
*/

int main(void){
    int h,w; cin >> h >> w;
    string s[h];
    rep(i,0,h){
        cin >> s[i];
    }
    rep(i,0,w+2) cout << "#";
    cout << "\n";
    
    rep(i,0,h){
        cout << "#";
        cout << s[i] <<"#\n";
    }
    rep(i,0,w+2) cout << "#";
    cout << "\n";
}