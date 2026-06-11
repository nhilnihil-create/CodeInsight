#include <bits/stdc++.h>

using namespace std;
 
#define IOS		    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ld 		    long double
#define ll 		    long long int
#define ull 	   	    unsigned long long int
#define pb		    push_back
#define mp		    make_pair
#define F		    first
#define S		    second
#define lb		    lower_bound
#define ub		    upper_bound
#define deb(x)      	    cout<<"#x "<<x<<"\n";
#define trace(x,y)  	    cout<<"#x "<<x<<" #y "<<y<<"\n";
#define cn          	    cout<<"\n";


bool SBF(const pair <int,int>& a, const pair<int,int>& b){return a.F<b.F;}
bool SBS(const pair <int,int>& a, const pair<int,int>& b){return a.S<b.S;}


const long double PI  = 3.1415926535;
const long long   mod = 1e9+ 7; 
const int 	  mxN = 1000;













void solve(){
	string s;
	cin >> s;
	string ret = "";
	for(int i=0;i<s.length(); i++){
		if(s[i] == ',')ret += " ";
		else ret += s[i];
	}
	cout<<ret<<"\n";
}
int main(){
	solve();
	return 0;
}
