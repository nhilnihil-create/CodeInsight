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
#define sbs(i,j) substr(i,j)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e6+10;
const int INF = 0x3f3f3f3f;
const int inf = - INF;
const int mod = 1e9+7;
const double pi = acos(-1.0);

int a[N];
int b[N];
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    rep(i,1,n){
        cin>>a[i];
        b[a[i]]++;
    }
    bool flag=true;
    if(n&1){
        if(b[0]!=1) flag=false;
        for(int i=2;i<=n-1;i+=2){
            if(b[i]!=2) flag=false;
        }
    }else{
        for(int i=1;i<=n-1;i+=2)
            if(b[i]!=2) flag=false;
    }
    ll res=1;
    for(int i=1;i<=n/2;i++)
        res=(res%mod)*2%mod;
    if(!flag) cout<<0<<endl;
    else cout<<res<<endl;
    return 0;
}