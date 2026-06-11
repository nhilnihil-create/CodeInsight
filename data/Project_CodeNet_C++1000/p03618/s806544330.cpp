#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;


int main(){
    string s;cin>>s;
    ll n=s.size();
    map<char,ll> m;
    rep(i,0,n)m[s[i]]++;
    ll an=0;
    for(auto i:m){
        ll num=i.second;
        an+=(num-1)*num/2;
    }
    cout<<n*(n-1)/2-an+1<<endl;
}
    







