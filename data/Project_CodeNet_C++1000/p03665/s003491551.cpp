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
    int n,p;cin>>n>>p;
    int a[n];
    bool flag=true;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]%2==1) flag=false;
    }
    if(flag){
        if(p==1) cout<<0<<endl;
        else cout<<power(2,n)<<endl;
        return 0;
    }
    cout<<power(2,n-1)<<endl;
    return 0;
}