#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a)  (a).begin(),(a).end()
#define pb emplace_back
#define INF (1e9+1)
//#define INF (1LL<<59)


int main(){
    int n;
    cin>>n;
    
    int sum=0;
    int c=1;
    while(sum<n){
        sum+=c;
        c++;
    }
    sum-=n;
    vector<int> v;
    for(int i=1;i<c;i++){
        if(i!=sum)v.pb(i);
    }
    rep(i,v.size()){
        if(i)cout<<" ";
        cout<<v[i];
    }
    cout<<endl;
    
}