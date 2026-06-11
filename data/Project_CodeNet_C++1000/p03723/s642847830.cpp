#include<bits/stdc++.h>
using namespace std;

#define pb 		push_back
#define mp 		make_pair
#define prior   priority_queue
#define MOD 	1000000007
#define INF64 	(long long)1e18
#define INF 	(int)1e9
#define PI 		3.1415926535897932384626433832795 
#define ll      long long
#define ld		long double
#define ret     return
#define NUM 	1000001
const int SIZE = 2e5+4;
void fastio(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
}

void solveTest(){
	
}

int main(){
	fastio();
	//input();

	/*int t;
	cin>>t;
	while(t--){
		solveTest();
	}*/

	ll a,b,c;
	cin>>a>>b>>c;
	ll cnt=0;
	while(a%2==0&&b%2==0&&c%2==0){
		if(a==b&&b==c){
			cout<<-1<<endl;
			return 0;
		}
		cnt++;
		ll x,y,z;
		x = b/2+c/2;
		y = a/2+c/2;
		z = a/2+b/2;
		a=x;b=y;c=z;		
	}
	cout<<cnt<<endl;
	return 0;
}
