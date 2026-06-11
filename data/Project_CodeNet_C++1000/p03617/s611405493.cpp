#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef long double ld;
const double pi=acos(-1.0);
const ll mod=pow(10,9)+7;
const ll INF=pow(2,31)-1;
typedef pair<int,int> P;
typedef vector<int> vi;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

ll gcd(ll a , ll b){
	if(b == 0) return a;
	return gcd(b , a % b);	
}
ll lcm(ll a , ll b){
	ll g = gcd(a , b);
	ll lc = (a/g) * b;
	return lc;
}

int main(){
    ios::sync_with_stdio(false);
    ll q,h,s,d,n;
    cin >> q >> h >> s >> d;
    cin >> n;
    ll ans=0;
    if(n%2==0){
        ans=min((n/2)*d,min(n*s,min(2*n*h,4*q*n)));
    } else{
        ll a=(n/2);
        ll b=min(a*d+s,min(a*d+2*h,a*d+4*q));
        ans=min(b,min(n*s,min(2*n*h,4*q*n)));
    }
    cout << ans << endl;
    return 0;
}