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
    vector<int> cnt(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        cnt[a]++;
        cnt[b]++;
    }
    for(int i=0;i<=n;i++){
        if(cnt[i]%2==1){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}