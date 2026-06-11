#include<bits/stdc++.h>
using namespace std;

struct BIT{
    int N;
    vector<int> dat;
    public:
    BIT(int n):N(n),dat(n){}
    void add(int pos,int x){
        pos++;
        while(pos<=N){
            dat[pos-1]+=x;
            pos+=(pos&-pos);
        }
    }
    int query(int r){
        int res=0;
        while(r>0){
            res+=dat[r-1];
            r-=(r&-r);
        }
        return res;
    }
    int query(int l,int r){
        return query(r)-query(l);
    }
};

struct Query{
    bool isGoods;
    int id;
    int l,r;
};

bool cmp(Query lhs,Query rhs){
    return lhs.l>rhs.l || lhs.l==rhs.l && (!lhs.isGoods)<(!rhs.isGoods);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> l(n),r(n);
    for(int i=0;i<n;i++) cin>>l[i]>>r[i];

    BIT bit(m+1);
    vector<Query> query;
    for(int i=0;i<n;i++) query.push_back({true,i,l[i],r[i]});
    for(int d=2;d<=m;d++){
        for(int j=0;j<=m;j+=d){
            int l=j+1,r=min(j+d,m+1);
            if(r-l>=1) query.push_back({false,d-1,l,r});
        }
    }
    sort(query.begin(),query.end(),cmp);

    vector<int> res(m,n);
    for(auto &q:query){
        if(q.isGoods){
            bit.add(q.r,1);
        }
        else{
            int sub=bit.query(q.l,q.r);
            res[q.id]-=sub;
        }
    }
    
    for(int i=0;i<m;i++){
        cout<<res[i]<<"\n";
    }
    return 0;
}