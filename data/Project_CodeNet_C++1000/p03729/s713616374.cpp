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
	string a,b,c;
	cin>>a>>b>>c;
	if(a[a.size()-1] ==b[0] && b[b.size()-1] ==c[0]) {
		cout<<"YES"<<endl;
	}
	else cout<<"NO";
}

