//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int m;
vector<int> bit;

void init_bit(){
    bit.assign(m+2,0);
}

void add(int a,int w){
    for(int i=a;i<=m+1;i+=i&-i) bit[i]+=w;
}

int sum(int a){
    int res=0;
    for(int i=a;i>0;i-=i&-i) res+=bit[i];
    return res;
}

int main(){
    int n; cin>>n>>m;
    init_bit();
    vector<vector<pp>> data(m+1);
    rep(i,n){
        int l,r; cin>>l>>r;
        data[r-l+1].push_back(mk(l,r));
    }
    int cnt=n;
    for(int i=1;i<=m;i++){
        for(auto p:data[i-1]){
            add(p.first,1);
            add(p.second+1,-1);
            cnt--;
        }
        int ans=cnt;
        for(int j=i;j<=m;j+=i) ans+=sum(j);
        printf("%d\n",ans);
    }
}
