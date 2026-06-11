#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout<< (x) << " "

int main(){
    ll q,h,s,d,n;cin>>q>>h>>s>>d>>n;
    vector<ll>v;
    v.push_back(4*q*n);
    v.push_back(2*h*n);
    v.push_back(s*n);
    v.push_back(n/2*d+n%2*s);
    v.push_back(n/2*d+n%2*q*4);
    v.push_back(n/2*d+n%2*h*2);
    sort(v.begin(),v.end());
    co(v[0]);
}