#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std ;
typedef long long ll ;
const int mod=1000000007 ;

void solve(){


	int n ;
	cin>>n ;
	set<int> st ;
	rep(i,n){
		int x ;
		cin>>x ;
		if(st.find(x)==st.end()){
			st.insert(x) ;
		}
		else{
			st.erase(x) ;
		}
	}

	cout<<st.size() ;

}


int main(){
	
	int y ;

	y=1 ;
	//cin>>y ;

	while(y--)
	{	
		solve() ;
	}

}