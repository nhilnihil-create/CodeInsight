#include <bits/stdc++.h>

using namespace std;
#define ll long long
const ll mx=1e18+7;

int main() {
	int a, b, c;
	cin>>a>>b>>c;
	int sum= a+b+c;
	
	if((a==sum/2 || b==sum/2 || c==sum/2 ) && sum%2==0 ){
		cout<<"Yes"<<endl;
		}	
	else cout<<"No"<<endl;	
	return 0;
}
