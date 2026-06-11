#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;
struct edge {int from,to,cost;};

signed main() {
int n,a,b,c,d;
cin>>n>>a>>b>>c>>d;
for(int i=0;i<=n-1;i++){
    if((max(a+i*c,b+(n-1-i)*c)<=min(a+i*d,b+(n-1-i)*d))){
        cout<<"YES";
       // cerr<<i;
        return 0;
    }
}
cout<<"NO";
return 0;


}
