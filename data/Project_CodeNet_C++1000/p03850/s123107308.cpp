#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pw(x) (1ll << (x))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,l,r) for(i=(l);i<(r);++i)
#define per(i,l,r) for(i=(r)-1;i>=(l);--i)
#define dd(x) cout << #x << " = " << x << ", "
#define de(x) cout << #x << " = " << x << endl
//-----
const int N=100005;
ll pre[N],rpre[N];
int vec[N],sz=0;
ll qry(int l,int r) {
  return pre[r]-pre[l-1];
}
ll mymax(ll a,ll b) {
  return a>b?a:b;
}
int main() {
  int i;
  sz=0;
  int n,a;scanf("%d%d",&n,&a);pre[1]=rpre[1]=a;
  rep(i,2,n+1) {
    char s[5];
    int a;scanf("%s%d",s,&a);
    pre[i]=pre[i-1]+a;
    if(s[0]=='-') {
      rpre[i]=rpre[i-1]-a;
      vec[sz++]=i;
    }
    else rpre[i]=rpre[i-1]+a;
  }
  ll ans=rpre[n];
  rep(i,0,sz-1)ans=mymax(ans,rpre[vec[i]-1]-qry(vec[i],vec[i+1]-1)+qry(vec[i+1],n));
  printf("%lld\n",ans);
  return 0;
}
