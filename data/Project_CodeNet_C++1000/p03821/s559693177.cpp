//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod= 1e+9+7;


int main(){
    ll n; cin>>n;
    vector<ll>a(n),b(n);
    rep(i,n)cin>>a[i]>>b[i];
    ll cnt=0;

    rep(i,n){
        a[n-1-i]+=cnt;
        ll s=b[n-1-i]-a[n-1-i]%b[n-1-i];
        if(s!=b[n-1-i]){
        cnt+=s;
        }

    }
    cout<<cnt<<endl;
}






