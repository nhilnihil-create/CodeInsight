#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;
const ll LINF=1e18;

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v[i]={a,-i};
    }
    sort(v.begin(),v.end());
    ll ans[n]={};
    int mx=v[n-1].first;
    int mxi=v[n-1].second;
    ll sum=mx;
    for(int i=n-2;i>=0;i--){
        if(v[i].second>mxi){
            ans[-mxi]=sum-(ll)v[i].first*(n-1-i);
            sum=(ll)v[i].first*(n-1-i);
            mx=v[i].first;
            mxi=v[i].second;
        }
        sum+=v[i].first;
    }
    ans[-mxi]=sum;
    for(int i=0;i<n;i++){
        cout<<ans[i]<<endl;
    }
}
