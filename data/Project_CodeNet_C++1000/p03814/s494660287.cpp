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
	string s;
	cin>>s;
	for(ll i=0; i<s.size(); i++){
		if(s[i]=='A'){
			ans=i;
			break;
		}
	}
	for(ll i=s.size()-1; i>=0; i--){
		if(s[i]=='Z') {
			sum=i;
			break;
		}
	}
	cout<<(sum-ans)+1<<endl;
}


