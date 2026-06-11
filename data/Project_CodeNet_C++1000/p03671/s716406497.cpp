#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0 ; i < (n); ++i)
using namespace std ;
typedef long long ll ;
const int mod=1000000007 ;

void solve(){

	int a,b,c ;
	cin>>a>>b>>c ;

	vector<int> v(3) ;

	v[0]=a ;
	v[1]=b ;
	v[2]=c ;

	sort(v.begin(),v.end()) ;

	int sum=0 ;

	rep(i,2){
		sum+=v[i] ;
	}

	cout<<sum ;
	
}


int main(){

		int y ;

		y=1 ;
		//cin>>y ;

		while(y--){
 
			solve() ;

		}

}