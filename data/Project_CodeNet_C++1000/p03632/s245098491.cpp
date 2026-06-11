#include <iostream>
using namespace std;

#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main() {
    int a[4];
    rep(i,4)cin>>a[i];
    int s,t;
    s = max(a[0],a[2]);
    t = min(a[1],a[3]);
    
    int ans = max(t - s, 0);
    cout<<ans<<endl;
	return 0;
}