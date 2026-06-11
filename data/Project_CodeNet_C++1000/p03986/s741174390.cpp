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
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ll> pll;
const int INF=1e9;
const ll MOD=1e9+7;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int dis2(int x1,int y1,int x2,int y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
ll inf=998244353;
ll power(ll a,ll x){
    ll res=1;
    while(x>0){
        if(x&1) res=res*x%inf;
        x=x*x%inf;
        x>>=1;
    }
    return res;
}
int main(){
    string x;cin>>x;
    int cs=0,ct=0;
    for(int i=0;i<(int)x.size();i++){
        if(x[i]=='S') cs++;
        else{
            if(cs>0) cs--;
            else ct++;
        }
    }
    cout<<cs+ct<<endl;
    return 0;
}