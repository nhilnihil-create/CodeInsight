#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

int main() {
	long long n,ans=0,bulk=0;
	cin>>n;
	vector<int>a(n);
	rep(i,n)cin>>a[i];
	rep(i,n){
	    if(a[i])bulk+=a[i];
	    else{
	        ans+=(bulk/2);
	        bulk=0;
	    }
	}
	ans+=(bulk/2);
	cout<<ans;
	return 0;
}
