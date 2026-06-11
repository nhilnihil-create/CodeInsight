#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0 ; i < (n); ++i)
using namespace std ;
typedef long long ll ;
const int mod=1000000007 ;

void solve(){

	int n ;
	cin>>n ;

	unordered_map<int,int> mp ;

	rep(i,n){
		
		int x ;
		cin>>x ;

		mp[x]++ ;
		
		x=x-1 ;
		mp[x]++ ;
		
		x=x+2 ;
		mp[x]++ ;

	}

	int max_second=0 ;

	for(auto x:mp){
		if(x.second>max_second){
			max_second=x.second ;
		
		}
	}
	
	cout<<max_second ;
}


int main(){

	

		int y ;

		y=1 ;
		//cin>>y ;

		while(y--){
 
			solve() ;

		}

}