#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
const double eps = 1e-10;
const int maxn = 1e5 + 100;
vector<int>g;
long long a[maxn],sum[maxn],ss[maxn]; char s[maxn];
int main() {
#ifdef ac
    freopen("in.txt" , "r" , stdin);
//    freopen("out.txt" , "w" , stdout);
#endif
    int n;
    cin >> n;
    cin >> a[1];
    if(n==1)
    sum[0]=0;ss[0]=0;
    sum[1]=ss[1]=a[1];int flag=0;

    for(int i=2;i<=n;++i) {
        cin >> s[i] >> a[i];
        sum[i]=sum[i-1]+a[i];
        if(s[i]=='-'){g.push_back(i);ss[i]=ss[i-1]-a[i];flag=1;}
        else ss[i]=ss[i-1]+a[i];
    }
    if(!flag){cout <<sum[n]<<endl;return 0;}
    ss[n+1]=ss[n];sum[n+1]=sum[n];
    g.push_back(g[g.size()-1]+1);
    long long ans=ss[n];
    for(int i=0;i<g.size()-1;++i) {
        int x=g[i],y=g[i+1]-1;

        ans=max(ss[x-1]-(sum[y]-sum[x-1])+(sum[n]-sum[y]),ans);
//         cout <<x << " " << y << " " << ans << endl;
    }
    cout << ans << endl;
    return 0;
}
