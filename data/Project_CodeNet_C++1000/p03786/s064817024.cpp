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
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    vector<ll> s(n+1,0);
    for(int i=0;i<n;i++) s[i+1]=a[i]+s[i];
    int ans=1;
    for(int i=n-1;i>0;i--){
        if(s[i]*2<a[i]) break;
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}