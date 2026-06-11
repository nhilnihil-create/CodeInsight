#include <bits/stdc++.h>
#define rep(i,s,n) for(int i=s;i<n;i++)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define int long long
using namespace std;
using P=pair<int,int>;
using Graph=vector<vector<int>>;
using ll=long long;



signed main(){
    int n,k; cin>>n>>k;
    
    int ans=k;
    for(int i=1;i<n;i++){
        ans *= (k-1);
    }
    
    cout<<ans<<endl;
}   