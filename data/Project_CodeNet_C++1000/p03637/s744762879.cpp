#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

int main() {
	int n,m,ans=0,ki=0,fo=0;
	cin>>n;
	vector<int>s(n);
	rep(i,n){
	    cin>>s[i];
	    if(s[i]%2)ki++;
	    else if(s[i]%4==0)fo++;
	}
	if(fo>=ki)ans=1;
	else if(fo+ki==n&&fo>=ki-1)ans=1;
	if(ans)cout<<"Yes";
	else cout<<"No";
	return 0;
}
