#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>

#ifdef PRINTERS
#include "printers.hpp"
using namespace printers;
#define tr(a)		cerr<<#a<<" : "<<a<<endl;
#else
#define tr(a)    
#endif

#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
#define tostring    to_string
using namespace std;
bool getinp(string s){
	cout<<"? "<<s<<endl;
	cout.flush();
	char ch;
	cin>>ch;
	return ch=='Y';
}
void output(ll ans){
	cout<<"! "<<ans<<endl;
	cout.flush();
	return;
}
void solve(){

	if(!getinp(string(9,'9'))){
		output(1000000000);
		return;
	}
	if(!getinp(string(8,'9'))){
		//10**8...10**9
		ll mina=100000000-1;
		ll maxa=1000000000-1;
		while(maxa-mina>1){
			ll mid=mina+(maxa-mina)/2;
			if(!getinp(tostring(mid*10))){
				mina=mid;
			}
			else{
				maxa=mid;
			}
		}
		output(maxa);
		return;
	}
	if(!getinp(string(7,'9'))){
		ll mina=10000000-1;
		ll maxa=100000000-1;
		while(maxa-mina>1){
			ll mid=mina+(maxa-mina)/2;
			if(!getinp(tostring(mid*10))){
				mina=mid;
			}
			else{
				maxa=mid;
			}
		}
		output(maxa);
		return;
	}
	if(!getinp(string(6,'9'))){
		ll mina=1000000-1;
		ll maxa=10000000-1;
		while(maxa-mina>1){
			ll mid=mina+(maxa-mina)/2;
			if(!getinp(tostring(mid*10))){
				mina=mid;
			}
			else{
				maxa=mid;
			}
		}
		output(maxa);
		return;
	}
	if(!getinp(string(5,'9'))){
		ll mina=100000-1;
		ll maxa=1000000-1;
		while(maxa-mina>1){
			ll mid=mina+(maxa-mina)/2;
			if(!getinp(tostring(mid*10))){
				mina=mid;
			}
			else{
				maxa=mid;
			}
		}
		output(maxa);
		return;
	}
	if(!getinp(string(4,'9'))){
		ll mina=10000-1;
		ll maxa=100000-1;
		while(maxa-mina>1){
			ll mid=mina+(maxa-mina)/2;
			if(!getinp(tostring(mid*10))){
				mina=mid;
			}
			else{
				maxa=mid;
			}
		}
		output(maxa);
		return;
	}
	if(!getinp(string(3,'9'))){
		ll mina=1000-1;
		ll maxa=10000-1;
		while(maxa-mina>1){
			ll mid=mina+(maxa-mina)/2;
			if(!getinp(tostring(mid*10))){
				mina=mid;
			}
			else{
				maxa=mid;
			}
		}
		output(maxa);
		return;
	}
	if(!getinp(string(2,'9'))){
		ll mina=100-1;
		ll maxa=1000-1;
		while(maxa-mina>1){
			ll mid=mina+(maxa-mina)/2;
			if(!getinp(tostring(mid*10))){
				mina=mid;
			}
			else{
				maxa=mid;
			}
		}
		output(maxa);
		return;
	}
	if(!getinp(string(1,'9'))){
		ll mina=10-1;
		ll maxa=100-1;
		while(maxa-mina>1){
			ll mid=mina+(maxa-mina)/2;
			if(!getinp(tostring(mid*10))){
				mina=mid;
			}
			else{
				maxa=mid;
			}
		}
		output(maxa);
		return;
	}
	ll mina=1-1;
	ll maxa=10-1;
	while(maxa-mina>1){
		ll mid=mina+(maxa-mina)/2;
		if(!getinp(tostring(mid*10))){
			mina=mid;
		}
		else{
			maxa=mid;
		}
	}
	if(maxa==1){
		if(getinp("100000000000000")){
			output(1);
		}
		else if(!getinp("100")){
			output(99);
		}
		else if(!getinp("1000")){
			output(999);
		}
		else if(!getinp("10000")){
			output(9999);
		}
		else if(!getinp("100000")){
			output(99999);
		}
		else if(!getinp("1000000")){
			output(999999);
		}
		else if(!getinp("10000000")){
			output(9999999);
		}
		else if(!getinp("100000000")){
			output(99999999);
		}
		else if(!getinp("1000000000")){
			output(999999999);
		}
		return;
	}
	else{
		output(maxa);
	}
	return;
	
}

int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(0);
	// cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}