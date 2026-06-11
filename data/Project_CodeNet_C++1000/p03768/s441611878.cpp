#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<set>
#include<map>
#include<bitset>

using namespace std;
typedef long long ll;
#define i_7 (ll)(1E9+7)
#define i_5 (ll)(1E9+5)
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<int,int> i_i;
typedef pair<ll,ll> l_l;
ll inf=(ll)1E12;/*10^12*/
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}

////////////////////////////////////////

int main(){
    int n,m;cin>>n>>m;
    vector<int>e[n];
    rep(i,1,m){
        int a,b;cin>>a>>b;
        a--;b--;
        e[a].pb(b);e[b].pb(a);
    }
    int q;cin>>q;
    int query[q][3];
    rep(i,0,q-1){
        rep(j,0,2)cin>>query[i][j];
        query[i][0]--;
    }
    int color[n];memset(color,0,sizeof(color));
    int neg[n];rep(i,0,n-1)neg[i]=-1;
    for(int i=q-1;i>=0;i--){
        int v=query[i][0];
        int d=query[i][1];
        int c=query[i][2];
        queue<i_i>q;
        q.push(i_i(v,d));
        
        while(!q.empty()){
            i_i t=q.front();
            q.pop();
            int nowv=t.first,nowd=t.second;
            if(color[nowv]==0)color[nowv]=c;
            if(nowd<=0)continue;
            for(auto x:e[nowv]){
                if(neg[x]<nowd-1){
                    q.push(i_i(x,nowd-1));
                    neg[x]=nowd-1;
                }
            }
        }
    }
    rep(i,0,n-1){
        cout<<color[i]<<endl;
    }
    return 0;
}