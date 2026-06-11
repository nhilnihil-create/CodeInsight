#include<bits/stdc++.h>
using namespace std;

struct BIT{
    int N;
    vector<int> dat;
    public:
    BIT(int n):N(n),dat(n+1,0){}
    void add(int pos,int val){
        pos++;
        while(pos<=N){
            dat[pos]+=val;
            pos+=pos&-pos;
        }
    }
    //sum of [0,pos) (dat[1..pos])
    int sum(int pos){
        int res=0;
        while(pos>0){
            res+=dat[pos];
            pos-=pos&-pos;
        }
        return res;
    }
    void debug(){
        for(int i=0;i<dat.size();i++){
            cout<<"#"<<i<<": "<<dat[i]<<endl;
        }
        return;
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    BIT bit(m+3);
    vector<pair<int,int>> lr(n);
    for(int i=0;i<n;i++){
        cin>>lr[i].first>>lr[i].second;
        lr[i].second++;
        bit.add(lr[i].second,1);
    }
    sort(lr.begin(),lr.end());
    vector<vector<int>> events(m+3);
    for(int i=0;i<m;i++) events[0].push_back(i);
    vector<int> ans(m,n);
    int inde=0;
    for(int i=0;i<=m;i++){
        while(inde<n && lr[inde].first<=i){
            bit.add(lr[inde].second,-1);
            inde++;
        }
        for(int j=0;j<events[i].size();j++){
            int l=i+1,r=i+events[i][j]+1;
            if(r>m+2) r=m+2;
            ans[events[i][j]]-=(bit.sum(r+1)-bit.sum(l));
            if(r<m) events[r].push_back(events[i][j]);
        }
    }
    for(int i=0;i<m;i++) cout<<ans[i]<<endl;
    return 0;
}