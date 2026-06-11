#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <cstdint>
#include <sstream>
#include <map>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;
typedef long long ll;

ll ans, mx, sum, mn = 1e8, cnt;


int main(){
	ll n;
	cin>>n;
	string s,t;
	cin>>s>>t;
	
	for(ll i=0; i<n; i++){
		string shelp,thelp;
		if(s[i]==t[0]){
			for(ll j=i; j<n; j++){
				shelp+=s[j];
			}
			for(ll j=0; j<n-i; j++){
				thelp+=t[j];
			}
			if(shelp==thelp){
				cout<<(2*n)-(shelp.size())<<endl;
				return 0;
			}
		}
	}
	cout<<n*2;
}

