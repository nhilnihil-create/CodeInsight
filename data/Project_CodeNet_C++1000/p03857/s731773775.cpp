#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int par[200010];
int ranks[200010];

void init(int n){
    for(int i=0; i<n; i++){
        par[i]=i;
        ranks[i]=0;
    }
}

int find(int x){
    if(par[x] == x){
        return x;
    }
    else{
        return par[x]=find(par[x]);
    }
}

bool same(int x, int y){
    return find(x) == find(y);
}

void unite(int x, int y){
    x=find(x);
    y=find(y);
    if(x == y) return;

    if(ranks[x] < ranks[y]){
        par[x]=y;
    }
    else{
        par[y]=x;
    }
    
    if(ranks[x] == ranks[y]){
        ranks[x]++;
    }
}

int par2[200010];
int ranks2[200010];

void init2(int n){
    for(int i=0; i<n; i++){
        par2[i]=i;
        ranks2[i]=0;
    }
}

int find2(int x){
    if(par2[x] == x){
        return x;
    }
    else{
        return par2[x]=find2(par2[x]);
    }
}

bool same2(int x, int y){
    return find2(x) == find2(y);
}

void unite2(int x, int y){
    x=find2(x);
    y=find2(y);
    if(x == y) return;

    if(ranks2[x] < ranks2[y]){
        par2[x]=y;
    }
    else{
        par2[y]=x;
    }
    
    if(ranks2[x] == ranks2[y]){
        ranks2[x]++;
    }
}

int main(){
    int n, k, l; cin>>n>>k>>l;
    init(n);
    init2(n);
    for(int i=0; i<k; i++){
        int p, q; cin>>p>>q;
        p--, q--;
        unite(p, q);
    }
    for(int i=0; i<l; i++){
        int r, s; cin>>r>>s;
        r--, s--;
        unite2(r, s);
    }
    
    map<P, int> ans;
    for(int i=0; i<n; i++){
        ans[P(find(i), find2(i))]++;
    }

    for(int i=0; i<n; i++){
        cout << ans[P(find(i), find2(i))] << " ";
    }
}