#include <bits/stdc++.h>
#define rep(i,n) for (ll i=0; i<(n); i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
 
int main(){
    char a,b; cin >> a >> b;
    bool ok=false;
    if (a=='H' && b=='H') ok=true;
    if (a=='D' && b=='D') ok=true;
    
    if (ok) cout << 'H' << endl;
    else cout << 'D' << endl;
    return 0;
}