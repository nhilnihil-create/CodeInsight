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
	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	cout<<max(a*b,c*d);
}
