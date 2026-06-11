#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
typedef pair<int,int> pii;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a) (a).begin(),(a).end()
#define pb emplace_back
#define INF (1e9+1)

signed main(){
    int k;
    cin>>k;
    
    priority_queue<int,vector<int>,greater<int>> pq;
    rep(i,50)pq.push(i + k/50);
    
    k%=50;
    
    cout<<50<<endl;
    rep(i,50){
        int q = pq.top();
        pq.pop();
        
        if(i<k){
            cout<<q+50-k+1<<" ";
        }
        else cout<<q-k<<" ";
    }
    cout<<endl;
}