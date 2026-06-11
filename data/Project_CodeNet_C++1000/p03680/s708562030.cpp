#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

void solve(){
	
	int n ;
	cin>>n ;

	pair<int,bool> arr[n+1] ;

	arr[0].first=-1 ;

	for(int i=1;i<=n;i++){
		cin>>arr[i].first ;
		arr[i].second=false ;
	}

	int source=1 ;
	int steps=1 ;

	while(arr[source].second==false){

		//cout<<arr[source].first<<" "<<arr[source].second<<"\n" ;

		if(arr[source].first==2)
			{	
				cout<<steps ;
				return ;
			}

		arr[source].second=true ;
		source=arr[source].first ;
		steps++ ;
	
	}
		
	cout<<-1 ;

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