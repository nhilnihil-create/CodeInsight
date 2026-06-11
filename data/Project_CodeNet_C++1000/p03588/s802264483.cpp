#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n,a,b,ma=0,mb=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		if(a>ma){
			ma=a;
			mb=b;
		}
	}
	cout<<ma+mb<<endl;
	return 0;
}