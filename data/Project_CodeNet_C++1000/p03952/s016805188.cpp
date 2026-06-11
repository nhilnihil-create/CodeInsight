#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 

int main() {
	ll n,b;
	cin>>n>>b;
	if(b==1||b==2*n-1){
		cout << "No";
		return 0;
	}
	ll a=b-1,c=b+1;
	ll now=1;
	cout << "Yes"<<endl;
	ll mid=(2*n)/2;
	for(ll i=1;i<=2*n-1;i++){
		if(i==mid-1){
			cout <<a;
		}
		else if(i==mid){
			cout << b;
		}
		else if(i==mid+1){
			cout << c;
		}
		else{
			if(now==a){
				now=a+3;
			}
			cout << now;
			now++;
		}
		cout <<endl;
	}
	return 0;
}