#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <cstdint>
#include <map>
 
using namespace std;
typedef long long ll;


ll ans,mx,sum,mn=1e8;
int main(){
	ll n,m;
	cin>>n>>m;
	if(n*2 >= m){
		cout<<m/2;
	}
	else cout<<n+(m-(n*2))/4<<endl;
}
