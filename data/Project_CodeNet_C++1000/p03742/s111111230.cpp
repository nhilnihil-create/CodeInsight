#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define mst(a, b) memset(a, b, sizeof(a))
#define X first
#define Y second
#define lowbit(x) (x&(-x))
const int maxn = 100+10;
const int maxm = 10000+10;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
//int sg[maxn][maxn];
//int get_sg(int x,int y){
//    if (x>y) swap(x,y);
//    if (~sg[x][y]) return sg[x][y];
//    bool f[100]={0};
//    for (int i=2;i<=x;i+=2){
//        f[get_sg(x-i,y+i/2)]=true;
//    }
//    for (int i=2;i<=y;i+=2){
//        f[get_sg(x+i/2,y-i)]=true;
//    }
//    for (int i=0;;i++) if (!f[i]) return i;
//}
int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
//    mst(sg,-1);
//    int n=10;
//    for (int i=0;i<=n;i++) for (int j=i;j<=n;j++){
//        cout<<i<<" "<<j<<" "<<get_sg(i,j)<<"\n";
//    }
    ll x,y; cin>>x>>y;
    if (x>y) swap(x,y);
    if (x==y || x+1==y) cout<<"Brown\n"; else cout<<"Alice\n";
    return 0;
}
