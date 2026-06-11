#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0 ; i < (n); ++i)
using namespace std ;
typedef long long ll ;
const int mod=1000000007 ;

void solve(){

	string s ;
	cin>>s ;

	int n=s.length() ;

	for(int i=n-1;i>=0;i--){


		string temp=s.substr(0,i) ;

		int l=temp.length() ;
		if(l%2==0){

			string x=temp.substr(0,l/2) ;

			x=x+x ;
			if(x==temp){
				cout<<x.length() ;
				return ;
			}

		}

	//	cout<<temp<<"\n" ;
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