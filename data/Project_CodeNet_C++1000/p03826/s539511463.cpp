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
    int A,B,C,D; cin >> A >> B >> C >> D;
    int ans1=A*B;
    int ans2=C*D;
    
    if (ans1>=ans2) cout << ans1 << endl;
    else cout << ans2 << endl;
    return 0;
}