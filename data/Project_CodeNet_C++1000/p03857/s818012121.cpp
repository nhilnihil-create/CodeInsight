#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<map>
#include<functional>
#include<queue>
#include<stack>
#include<string.h>
#define ll long long int
#define MOD 1000000007LL
using namespace std;
int par[1000000];//親
int fukasa[1000000];//深さ
//初期化
void init(int n){
    for(int i=0;i<n;i++){
        par[i]=i;
        fukasa[i]=0;
    }
}
//木の根を求める
int find(int x){
    if(par[x]==x){
        return x;
    }else{
        return par[x]=find(par[x]);
    }
}
//xとyの集合を併合
void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y){
        return;
    }
    if(fukasa[x]<fukasa[y]){
        par[x]=y;
    }else{
        par[y]=x;
        if(fukasa[x]==fukasa[y]){
            fukasa[x]++;
        }
    }
}
//xとyが同じ集合に属する?
bool same(int x,int y){
    return find(x)==find(y);
}
int main() {
    int n,k,l;
    cin>>n>>k>>l;
    init(n);
    for(int i=0;i<k;i++){
        int p,q;
        cin>>p>>q;
        p--;q--;
        unite(p,q);
    }
    int a[364364]={};
    for(int i=0;i<n;i++){
        a[i]=find(i);
    }
    init(n);
    for(int i=0;i<l;i++){
        int r,s;
        cin>>r>>s;
        r--;s--;
        unite(r,s);
    }
    int b[364364]={};
    for(int i=0;i<n;i++){
        b[i]=find(i);
    }
    map<pair<int,int>,int> m;
    for(int i=0;i<n;i++){
        pair<int,int> p={a[i],b[i]};
        m[p]++;
    }
    for(int i=0;i<n;i++){
         pair<int,int> p={a[i],b[i]};
         cout<<m[p];
         if(i!=n-1){
             cout<<" ";
         }
    }
    cout<<endl;
}
