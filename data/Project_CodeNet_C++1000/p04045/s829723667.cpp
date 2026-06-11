#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <cstdint>
#include <sstream>
#include <map>
#include<vector>

using namespace std;
typedef long long ll;

ll ans,mx,sum,mn=1e8,cnt; 

int main(){
	
	ll n,k;
	cin>>n>>k;
	ll a[k];
	for(ll i=0; i<k; i++){
		cin>>a[i];
	}
	for(ll i=n; i<=100000; i++){
		string s=to_string(i);
		bool ok=true;
		for(ll j=0; j<s.size(); j++){
			for(ll h=0; h<k; h++){
				string g=to_string(a[h]);
				if(s[j]==g[0]){
					ok=false;
					break;
				}
			}
		}
		if(ok==true){
			cout<<i;
			return 0;
		}
	}
}
