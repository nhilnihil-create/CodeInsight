#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0 ; i < (n); ++i)
using namespace std ;
typedef long long ll ;
const int mod=1000000007 ;

void solve(){

	string s ;
	cin>>s ;

	string temp="" ;

	for(int i=0;i<(int)s.length();i=i+2){
		temp=temp+s[i] ;
	}
	
	cout<<temp ;
}


int main(){

		int y ;

		y=1 ;
		//cin>>y ;

		while(y--){
 
			solve() ;

		}

}