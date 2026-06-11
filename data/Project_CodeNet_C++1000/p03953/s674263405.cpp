#include<bits/stdc++.h>
using namespace std;

using ll=long long;
array<int,200000> buf;
void merge(vector<int>& lhs,vector<int> rhs){
    int n=lhs.size();
    for(int i=0;i<n;i++){
        buf[i]=lhs[rhs[i]];
    }
    for(int i=0;i<n;i++) lhs[i]=buf[i];
}
int main(){
    int n;
    cin>>n;
    vector<ll> x(n);
    for(int i=0;i<n;i++) cin>>x[i];
    int m; ll k;
    cin>>m>>k;   
    vector<int> a(m);
    for(int i=0;i<m;i++) cin>>a[i],a[i]--;

    // cerr<<"#PERM PHASE"<<endl;
    vector<int> perm(n-1);
    iota(perm.begin(),perm.end(),0);
    for(int i=0;i<m;i++){
        // assert(0<=a[i]-1 && a[i]<n-1);
        swap(perm[a[i]-1],perm[a[i]]);
    }
    vector<int> diff(n-1);
    for(int i=0;i+1<n;i++) diff[i]=x[i+1]-x[i];

    // cerr<<"#POW PHASE"<<endl;
    while(k){
        if(k&1) merge(diff,perm);
        k>>=1;
        merge(perm,perm);
    }

    // cerr<<"#RESTORE PHASE"<<endl;
    vector<ll> res(n);
    res[0]=x[0];
    for(int i=1;i<n;i++){
        res[i]=res[i-1]+diff[i-1];
    }
    for(int i=0;i<n;i++){
        cout<<res[i]<<endl;
    }
    return 0;
}