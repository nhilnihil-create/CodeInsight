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

int main(){
    int n;cin>>n;
    vector<ll> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i]>>b[i];
    ll ans=0;
    for(int i=n-1;i>=0;i--){
        ans+=((a[i]+ans+b[i]-1)/b[i])*b[i] - (a[i]+ans);
    }
    cout<<ans<<endl;
    return 0;
}