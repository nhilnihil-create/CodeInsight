#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0 ; i < (n); ++i)
using namespace std ;
typedef long long ll ;
const int mod=1000000007 ;

void solve(){

	int n ;
	cin>>n ;

	vector<int> v(n) ;

	rep(i,n){
		cin>>v[i] ;
	}

	vector<int> ans ;

	for(int i=n-1;i>=0;i=i-2){
		ans.push_back(v[i]) ;
	}

	for(int i=((n%2!=0)?1:0);i<n;i=i+2){
		ans.push_back(v[i]) ;
	}

	rep(i,n){
		cout<<ans[i]<<" " ;
	}

}


int main(){

		int y ;

		y=1 ;
		//cin>>y ;

		while(y--){
 
			solve() ;

		}

}