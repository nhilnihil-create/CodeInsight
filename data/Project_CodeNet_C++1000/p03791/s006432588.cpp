#include<bits/stdc++.h>
using namespace std;

//typedef
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

//define
#define ALL(a) a.begin(),a.end()
#define REP(i,n) for(ll i=0;i<(n);i++)
#define RREP(i,n) for(ll i=n-1;i>=0;i--)
#define DEBUG(x) if(1)cout<<#x<<":"<<x<<endl;

//function
template<typename T>
istream& operator>>(istream& stream,vector<T> &v){
  for(int i=0;i<v.size();i++) cin>>v[i];
  return stream;
}
template<typename T>
ostream& operator<<(ostream& stream,vector<T> &v){
  for(int i=0;i<v.size();i++) cout<<v[i]<<endl;
  return stream;
}

const ll MOD=1e9+7;

int main(){  
	int n;
	cin>>n;
	vector<ll> x(n);
	cin>>x;
	ll res=1;
	ll space=0;
	ll goaled=0;
	for(int i=0;i<n;i++){
		space=x[i]-(i+1-goaled);
		if(space<i-goaled){
			res*=(i+1-goaled);
			goaled++;
		}
		res%=MOD;
	}
	for(int i=0;i<(n-goaled);i++){
		res*=(i+1);
		res%=MOD;
	}
	cout<<res<<endl;

  	return 0;
}
