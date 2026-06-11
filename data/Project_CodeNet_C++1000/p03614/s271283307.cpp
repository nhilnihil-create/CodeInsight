#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a) (a).begin(),(a).end()
#define pb emplace_back
#define INF (1e9+1)

int main(){
    int n;
    cin>>n;
    
    vector<int> p(n);
    rep(i,n)cin>>p[i];
    
    vector<bool> same(n);
    rep(i,n)if(p[i]==i+1)same[i]=true;
    
    int ans = 0;
    rep(i,same.size()){
        if(same[i]){
            same[i] = false;
            if(i+1<same.size())same[i+1] = false;
            ans++;
        }
    }
    cout<<ans<<endl;
}
