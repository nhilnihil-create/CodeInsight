#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define INF 1e9
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

ll gcd(ll x,ll y) {return y ? gcd(y,x%y) : x;}
ll lcm(ll x, ll y) {return x/gcd(x,y)*y;}


int main(){
	ll N,X; cin>>N>>X;
	ll res=N;
	ll a=max(N-X,X),b=min(N-X,X);

	while(b){
		ll q=a/b;
		ll r=a%b;

		res+=(b*2)*q;
		if(r==0) res-=b;
		a=b,b=r;
	}
	cout<<res<<endl;
}