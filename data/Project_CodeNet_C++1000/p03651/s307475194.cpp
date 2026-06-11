#include <bits/stdc++.h>
#define rep(i,s,n) for(int i=s;i<n;i++)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
using P=pair<int,int>;
using G=vector<vector<int>>;
using ll=long long;
ll N;

const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
int n,m;
int ans=0;

vector<vector<int>> grid;
vector<ll> H, S;
vector<bool> seen;
vector<ll>sum;
vector<int> pl;

int main(int argc, char **argv){
	ll n,k; cin>>n>>k;
	ll a[n];
	rep(i,0,n){
		cin>>a[i];
	}
	sort(a,a+n);
	if(a[n-1]<k){
		cout<<"IMPOSSIBLE"<<endl;
		return 0;
	}

	ll g=a[0];
	rep(i,0,n-1){
		g=__gcd(g,a[i+1]);
	}

	if(k%g==0){
		cout<<"POSSIBLE"<<endl;
		return 0;
	}else{
		cout<<"IMPOSSIBLE"<<endl;
		return 0;
	}
}
