#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define PB push_back
using namespace std;
typedef pair<int, int> P1;
typedef pair<int, pair<int, int> > P2;
static const int INF = 1ll<<60;
static const int dx[] = { 1, -1, 0, 0, };
static const int dy[] = { 0, 0, 1, -1 };
static const int mod = 1000000007;

int n,m;
int x[100005],y[100005];
int sum_x,sum_y;

signed main(){
    cin>>n>>m;
    for(int i=0;i<n;++i)cin>>x[i];
    for(int i=0;i<m;++i)cin>>y[i];
    for(int i=0;i<n;++i){
        sum_x+=i*x[i]-(n-i-1)*x[i];
        sum_x%=mod;
    }
    for(int i=0;i<m;++i){
        sum_y+=i*y[i]-(m-i-1)*y[i];
        sum_y%=mod;
    }
    cout<<(sum_x*sum_y)%mod<<endl;
}
