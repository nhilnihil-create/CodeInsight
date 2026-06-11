#include<bits/stdc++.h>
#define ll long long
#define re register
#define cs const

ll solve(ll a,ll b){
	return b%a?b/a*2*a+solve(b%a,a):(b*2-a);
}

ll n,x;

void Main(){
	std::cin>>n>>x;
	std::cout<<solve(x,n-x)+n<<"\n";
}

inline void file(){
	
}signed main(){file();Main();return 0;}