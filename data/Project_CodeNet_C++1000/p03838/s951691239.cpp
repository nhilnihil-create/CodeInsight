#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <cstdint>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;
typedef long long ll;


ll ans, mx, mn, flag, sum, cnt;

int main(){
	ll x,y;
	cin>>x>>y;
	if(x>=0 && y>=0){
		if(y>=x) cout<<y-x;
		else if(y>0)cout<<(x-y)+2;
		else cout<<x+1;
	}
	else if(x>=0 && y<0){
		if(abs(y)>=x) cout<<(abs(y)-x)+1;
		else cout<<(x-abs(y))+1;
	}
	else if(x<0 && y>=0){
		if(y>=abs(x)) cout<<(y-abs(x))+1;
		else if(y>0) cout<<(abs(x)-y)+1;
		else if(y==0) cout<<abs(x);
	}
	else if(x<0 && y<0){
		if(abs(x)>=abs(y)) cout<<abs(x)-abs(y);
		else cout<<(abs(y)-abs(x))+2;
	}
	
	
}
