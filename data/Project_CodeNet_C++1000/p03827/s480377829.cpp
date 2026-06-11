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
	ll n;
	cin>>n;
	string s;
	cin>>s;
	ll x=0;
	for(ll i=0; i<n; i++){
		if(s[i]=='I'){
			x++;
			mx=max(mx,x);
		}
		else {
			x--;
			mx=max(mx,x);
		}
	}
	cout<<mx<<endl;
}
