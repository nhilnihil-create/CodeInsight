#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <queue>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()

int main() {
    int n,m,ans;
    cin>>n>>m;
    vector<long long>x(n),y(n),a(m),b(m);
    rep(i,n)cin>>x[i]>>y[i];
    rep(j,m)cin>>a[j]>>b[j];
    long long d,l;
    rep(i,n){
        d=1000000000000000000;
        rep(j,m){
            l=abs(x[i]-a[j])+abs(y[i]-b[j]);
            if(l<d){
                d=l;
                ans=j+1;
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}
