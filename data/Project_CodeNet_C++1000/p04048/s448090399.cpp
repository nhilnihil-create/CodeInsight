#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f(z) for(int i=1;i<=z;i++)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define vi vector<int>
#define pb push_back
#define si set<int>
#define mod  1000000007
#define cl(n,m) (n-1)/m  + 1 ;
#define T() int TT; cin>>TT; while(TT--)
#define P pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
const int N = 2e6 + 5 ;

int gcd( int a ,int  b ){
	//cout << a <<" " << b << endl ;
	
	if( b == 0 )
		return  b - a ; 
	if(a > b ) swap(a , b) ;
	
	return 2*a*(b/a) + gcd(a , b%a ) ; 
}
signed main(){
	int n , x ;
	cin >> n >> x ;
	cout << n + gcd( n-x , x) ;
}