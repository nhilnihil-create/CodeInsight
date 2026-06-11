#include <bits/stdc++.h> 
#define forn(i,a,b) for(int i=a; i<=b; i++)
#define ford(i,a,b) for(int i=a; i>=b; i--)
#define pb push_back
#define mp make_pair
using namespace std;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n,k,x,y;
	cin>>n>>k>>x>>y;
	int cost=0;
	if(n<=k) cost+=(x*n);
	else cost+=((x*k) + (y*(n-k)));
	cout<<cost<<endl; 
}