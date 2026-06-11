#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=mod*mod*3LL;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int a, b, c;
    cin >> a >> b >> c;
    bool maki = false;
    for(int i=1;i<=b;i++){
    	if((i*a)%b == c)maki = true;
    }
    if(maki) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
