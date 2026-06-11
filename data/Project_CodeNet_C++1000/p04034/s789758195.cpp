#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<set>
#include<utility>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ii> P;
typedef unsigned long long int ull;
const int MOD=1e9+7;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const ll INF=2e18;

ll power(ll a,ll x){
    ll res=1;
    while(x>0){
        if(x&1){
            res*=a;
        }
        a*=a;
        x>>=1;
    }
    return res;
}

int main(){
    int n,m;cin>>n>>m;
    vector<int> cnt(n,1);
    vector<bool> p(n,false);
    p[0]=true;
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        x--;y--;
        p[y]=p[y]||p[x];
        cnt[y]++;
        cnt[x]--;
        if(cnt[x]==0) p[x]=false;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(p[i]) ans++;
    }
    cout<<ans<<endl;
    return 0;
}