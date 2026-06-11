#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
const int INF=1e9;

struct UnionFind{
    vector<int> par,rank;
    int c;
    UnionFind(int n):par(n),rank(n,0){
        for(int i=0;i<n;i++) par[i]=1;
        c=n;
    }
    int root(int x){
        if(par[x]==x) return x;
        return par[x]=root(par[x]);
    }
    void unite(int x,int y){
        int rx=root(x);
        int ry=root(y);
        if(rx==ry) return;
        if(rank[rx]<rank[ry]){
            par[rx]=ry;
        }
        else{
            par[ry]=rx;
            if(rank[rx]==rank[ry]) rx++;
        }
        c--;
    }
    bool same(int x,int y){
        return root(x)==root(y);
    }
    
};

int main()
{
    int a,b,c;cin>>a>>b>>c;
    int ans=0;
    while(true){
        if(a&1||b&1||c&1) break;
        if(a==b&&b==c){
            ans=-1;break;
        }
        int p,q,r;
        p=a/2;q=b/2;r=c/2;
        a=q+r;b=p+r;c=p+q;
      ans++;
    }
    cout<<ans<<endl;
    return 0;
}