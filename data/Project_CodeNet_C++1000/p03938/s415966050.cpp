#pragma GCC optimize("Ofast")
#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,long double> Pi;
typedef pair <long double,int> Pd;
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
const ll mod=1000000007;
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
ll pl=12000;
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
cin>>n;
vector<int> p(n),r(n);
vector<ll> a(n),b(n);
for(int i=0;i<n;i++){cin>>p[i];r[p[i]-1]=i+1;}
for(int i=0;i<n;i++){
    a[i]=30000*(i+1);
    b[i]=30000*(n-i)+r[i];
}
for(int i=0;i<n;i++)cout<<a[i]<<" ";
cout<<endl;
for(int i=0;i<n;i++)cout<<b[i]<<" ";
cout<<endl;
}

