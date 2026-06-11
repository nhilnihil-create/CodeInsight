#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds;
using namespace std;

using key=pair<int,int>;
using Tree=tree<key,null_type,less<key>,rb_tree_tag,tree_order_statistics_node_update>;

struct Query{
    int index;
    int l,r;
};

int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> lr(n);
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        r++;
        lr[i]={l,r};
    }

    sort(lr.begin(),lr.end(),[](pair<int,int> &lhs,pair<int,int> &rhs){return lhs.first>rhs.first;});
    vector<int> ans(m,n);
    vector<Query> query;
    for(int i=0;i<m;i++){
        int d=i+1;
        for(int j=d;j-d<=m;j+=d){
            query.push_back(Query{i,j+1-d,j});
        }        
    }

    sort(query.begin(),query.end(),[](Query &a,Query &b){return a.l>b.l;});
    Tree t;

    int inde=0;
    for(int i=0;i<query.size();i++){
        while(inde<n && query[i].l<=lr[inde].first){
            t.insert({lr[inde].second,inde});
            inde++;
        }
        ans[query[i].index]-=t.order_of_key({query[i].r+1,-100});
    }
    for(int i=0;i<m;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
