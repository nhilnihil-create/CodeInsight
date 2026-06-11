#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#define fi first
#define se second
#define pb(i) push_back(i)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define mes(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e6+10;
const int INF = 0x3f3f3f3f;
const int inf = - INF;
const int mod = 1e9+7;
const double pi = acos(-1.0);

int t[1005],a[1005];
int main(){
    int n;
    cin>>n;
    rep(i,1,n)
        cin>>t[i]>>a[i];
    ll A=1,B=1;
    ll k;
    rep(i,1,n){
        ll ka=A/t[i],kb=B/a[i];
        ka+=(A%t[i]==0)?0:1;
        kb+=(B%a[i]==0)?0:1;
        k=max(ka,kb);
        A=t[i]*k,B=a[i]*k;
    }
    cout<<A+B<<endl;
    return 0;
}