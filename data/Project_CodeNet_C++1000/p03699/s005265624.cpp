#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std ;
typedef long long ll ;
const int mod=1000000007 ;

void solve(){
	
	int n ;
	cin>>n ;

	priority_queue<int,vector<int>,greater<int>> pq1 ;
	priority_queue<int,vector<int>,greater<int>> pq2 ;

	int sum=0 ;

	rep(i,n){

		int x ;
		cin>>x ;

		if(x%10==0)
			pq1.push(x) ;
		else
			pq2.push(x) ;

		sum+=x ;

	}
 
	if(pq2.empty()){
		cout<<0 ;
		return ;
	}
	else{

		if(sum%10==0)
		{
			sum-=pq2.top() ;
			pq2.pop() ;
		
			cout<<sum ;
			return ;
		}
		else{

			cout<<sum ;
			return ;

		}

	}

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