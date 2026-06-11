#include<bits/stdc++.h>
#define ll long long int 
#define w(x) int x; cin>>x; while(x--)
#define pb push_back
#define mp make_pair
#define mod 1000000007
using namespace std;
int main(){
#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll n,A,B,c=0,b=0;
	cin>>n>>A>>B;
	string s;
	cin>>s;
	for(ll i=0; i<n; i++){
		if(s[i]=='c')
			cout<<"No"<<endl;
		else if(s[i]=='a' && c<A+B){
			c++;
			cout<<"Yes"<<endl;
		}
		else if(s[i]=='b' && b<B && c<A+B){
			c++;
			b++;
			cout<<"Yes"<<endl;
		}
		else 
			cout<<"No"<<endl;
	}
}