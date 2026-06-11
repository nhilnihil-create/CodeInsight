#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;

int main(){
    ll n,k;
    cin>>n>>k;
    vector<pair<int,int>> p(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        p[i]=make_pair(a,b);
    }
    sort(p.begin(),p.end());
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        if(i) v[i]=v[i-1]+p[i].second;
        else v[i]=p[i].second;
    }
    int i=lower_bound(v.begin(),v.end(),k)-v.begin();
    cout<<p[i].first<<endl;
}