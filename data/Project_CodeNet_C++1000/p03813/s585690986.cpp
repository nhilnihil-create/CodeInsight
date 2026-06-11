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
const long long   INF = 1e9;









int n , a, b;


void solve(){
 
	cin >> n;
	if(n <1200)cout<<"ABC\n";
	else cout<<"ARC\n";
}

int main(){
	solve();
	return 0;
}
