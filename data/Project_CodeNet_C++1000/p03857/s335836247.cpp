

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
#define i_7 1000000007
#define i_5 1000000005

ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<int,int> i_i;
typedef pair<ll,ll> l_l;
#define inf 100000000/*10^8*/



////////////////////////////////////////

#define MAX_N 200005//調節！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
int par[MAX_N],dep[MAX_N];//depはrankのこと
//n要素で初期化//忘れないように！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
void init(int n){
    for(int i=0;i<=n-1;i++){//頂点番号は0~n-1
        par[i]=i;
        dep[i]=0;
    }
}
//木の根を求める
int find(int x){
    return par[x]==x?x:par[x]=find(par[x]);
}
//xとyの属する集合を併合
void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y)return;
    if(dep[x]<dep[y]){
        par[x]=y;
    }else{
        par[y]=x;
        if(dep[x]==dep[y])dep[x]++;
    }
}
//xとyが同じ集合に属するか否か
bool same(int x,int y){
    return find(x)==find(y);
}

//////////////////////////////////////
int parb[MAX_N],depb[MAX_N];//depはrankのこと
//n要素で初期化//忘れないように！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
void initb(int n){
    for(int i=0;i<=n-1;i++){//頂点番号は0~n-1
        parb[i]=i;
        depb[i]=0;
    }
}
//木の根を求める
int findb(int x){
    return parb[x]==x?x:parb[x]=findb(parb[x]);
}
//xとyの属する集合を併合
void uniteb(int x,int y){
    x=findb(x);
    y=findb(y);
    if(x==y)return;
    if(depb[x]<depb[y]){
        parb[x]=y;
    }else{
        parb[y]=x;
        if(depb[x]==depb[y])depb[x]++;
    }
}
//xとyが同じ集合に属するか否か
bool sameb(int x,int y){
    return findb(x)==findb(y);
}
struct v{
    int rood;
    int train;
    int num;
};

bool asc(const v a,const v b){
    return a.rood==b.rood? a.train<b.train:a.rood<b.rood;
}

int main(){
    int n,k,l;cin>>n>>k>>l;
    init(n);initb(n);
    for(int i=1;i<=k;i++){
        int p,q;cin>>p>>q;p--;q--;
        unite(p,q);
    }
    for(int i=1;i<=l;i++){
        int p,q;cin>>p>>q;p--;q--;
        uniteb(p,q);
    }
    int ans[n];memset(ans,0,sizeof(ans));
    v p[n];
    for(int i=0;i<=n-1;i++){
        p[i].rood=find(i);
        p[i].train=findb(i);
        p[i].num=i;
    }
    sort(p,p+n,asc);
    int pos=0;
    while(pos<=n-1){
        int count=1;vector <int>c;c.push_back(p[pos].num);
        while(pos+1<=n-1&&p[pos].rood==p[pos+1].rood&&p[pos].train==p[pos+1].train){
            c.push_back(p[pos+1].num);
            pos++;
            count++;
        }
        for(auto x:c){
            ans[x]=count;
        }
        pos++;
    }
    
    for(int i=0;i<=n-1;i++)cout<<ans[i]<<" ";
    return 0;
}