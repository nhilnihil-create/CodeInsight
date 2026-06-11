#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <cstdint>
#include <sstream>
#include <map>
#include <cstring>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;
typedef long long ll;

ll ans, mx, sum, mn = 1e8, cnt;

ll ans1;
int main(){
	ll n;
	cin>>n;
	string b,s;
	cin>>b;
	s=b;
	for(ll i=0; i<n; i++){
		if(s[i]==')'){
			bool ok=false;
			for(ll j=0; j<i; j++){
				if(s[j]=='('){
					s[j]='#';
					ok=true;
					s[i]='#';
					break;
				}
			}
			if(ok==false) ans++;
		}
		else if(s[i]=='('){
			bool ok1=false;
			for(ll j=i; j<n; j++){
				if(s[j]==')'){
					s[i]='#';
					s[j]='#';
					ok1=true;
					break;
				}
			}
			if(ok1==false) ans1++;
		}
	}
	for(ll i=0; i<ans; i++) cout<<'(';
	cout<<b;
	for(ll i=0; i<ans1; i++) cout<<')';
	
}
