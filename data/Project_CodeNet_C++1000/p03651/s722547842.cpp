#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
#define rep2(i,a,n) for(int i=a;i<n;i++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
const ll INFL = 1e18;
const int INF = 1001001001; 
typedef pair<int,int> P;
#define foreach(ix,i) for(auto& (ix) : (i))
typedef long double ld;
const int mod =1000000007;
const double PI = acos(-1);

int main(){
	int n,k;cin>>n>>k;
	int g ;cin>>g;
	int ma =g;
	rep(i,n-1){
		int a;cin>>a;
		g = __gcd(g,a);
		ma=max(ma,a);
		if(a==k){
			cout<<"POSSIBLE"<<endl;
			return 0;
		}
	}
	if(ma<k){
		cout<<"IMPOSSIBLE"<<endl;
	}
	else if(k%g==0){
		cout<<"POSSIBLE"<<endl;
	}
	else{
		cout<<"IMPOSSIBLE"<<endl;
	}
	
}