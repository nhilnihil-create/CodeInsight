#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MOD = 1e9+7;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;
    cin >> a >> b;

    if(a == b) cout << "Draw" << endl;
    else if(a == 1) cout << "Alice" << endl;
    else if(b == 1) cout << "Bob" << endl;
    else cout << ( a>b ? "Alice" : "Bob" ) << endl;

    return 0;
}