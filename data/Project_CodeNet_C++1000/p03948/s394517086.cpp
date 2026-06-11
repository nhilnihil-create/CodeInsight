#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
const ll INF = numeric_limits<int>::max() / 2;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

    int n;cin>>n;
    ll t,mi=INF,dmax=-1,cnt=0;cin>>t;
    vector<ll> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    mi=a[0];
    for(int i=1;i<n;i++){
        if(dmax>a[i]-mi){
            
        }
        else if(dmax==a[i]-mi){
            cnt++;
        }
        else{
            cnt=1;
            dmax=a[i]-mi;
        }
        mi=min(mi,a[i]);
    }
    cout<<cnt<<endl;
}
