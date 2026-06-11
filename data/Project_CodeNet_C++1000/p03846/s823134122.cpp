/*
...........__________    							 |										    ___  __
.............|       |     						     |											 |   /
.............|       |     						     |									  		 |  /
.............|       |                               |                         __                | /      _______
.............|_______|  _______            _______   |______   ________   /|  /  |               |/       |      |
.............| \               | |      | |          |      |          | / | /   |               |\       |
.............|  \       _______| |      | |_______   |      |   _______|   |/    |               | \      |
.............|   \      |      | |      |         |  |      |  |       |   |     |               |  \     |
.........  __|    \__|  |______| |______| ________|  |      |_ |_______|   |     |__|           _|   \__ _|        .

*/
#include<bits/stdc++.h>
using namespace std ;
#define int 				long long
#define ull 				unsigned long long int
#define ld 					long double
#define vi 					vector<int>
#define vii 				vector<pair<int,int>>
#define vvi 				vector<vector<int>>
#define pf 					push_front
#define popb 				pop_back
#define pb 					push_back
#define eb 					emplace_back
#define pii 				pair<int,int>
#define prec(x) 			fixed<<setprecision(15)<<x
#define all(x) 				x.begin(),x.end()
#define rall(x) 			x.rbegin(),x.rend()
#define mset(a,b) 			memset(a,b,sizeof(a))
#define mcpy(a,b) 			memcpy(a,b,sizeof(a))
#define fo0(i,n) 			for(int i=0,i##end=n;i<i##end;i++)
#define fo1(i,n) 			for(int i=1,i##end=n;i<=i##end;i++)
#define fo(i,a,b) 			for(int i=a,i##end=b;i<=i##end;i++)
#define foe(i,x)			for(__typeof((x).end())i=(x).begin();i!=(x).end();++i)
#define fre(i,x)			for(__typeof((x).rend())i=(x).rbegin();i!=(x).rend();++i)
#define fast ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0)
#define inf 1e18
const int mod=1e9+7;
const int N=4e5+10;


int power(int x, unsigned int y, int p) 
{ 
	int res = 1;	 
	x = x % p; 
	while (y > 0) 
	{ 
		if (y & 1) 
			res = (res*x) % p; 

		y = y>>1; 
		x = (x*x) % p; 
	} 
	return res; 
}

void raushan_kumar(){
	int n;cin>>n;
	int a[n];
	map<int,int> m;
	set<int> s;
	int cnt=0;
	fo0(i,n){
		cin>>a[i];
		s.insert(a[i]);
		if(a[i]==0){
			cnt++;
		}
	}
	if(cnt==2){
		cout<<0;
		return;
	}
	if(n%2){
		if(s.size()==(n/2+1)){
			cout<<power(2,n/2,mod);
		}
		else{
			cout<<0;
		}
	}
	else{
		if(s.size()==(n/2)){
			cout<<power(2,n/2,mod);
		}
		else{
			cout<<0;
		}
	}
}

int32_t main()
{
	fast;int t=1;
	//cin>>t;
	while(t--){
		raushan_kumar();
	}

}