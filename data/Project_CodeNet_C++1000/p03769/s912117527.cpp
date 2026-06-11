#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<complex>
#define lol(i,n) for(ll i=0;i<n;i++)
#define mod 1000000007
typedef long long ll;
using namespace std;

int main(){
    ll n,k=100;cin>>n;n++;
    vector<ll> v;
    for(ll i=1;(1LL<<i)<=n;i++){
	if(n&(1LL<<(i-1))){v.push_back(k);k--;}
	v.push_back(i);
    }
    cout<<v.size()*2<<endl;
    for(auto x:v)cout<<x<<" ";
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
	cout<<v[i];
	if(i==v.size()-1)cout<<endl;
	else cout<<" ";
    }
    return 0;
}
