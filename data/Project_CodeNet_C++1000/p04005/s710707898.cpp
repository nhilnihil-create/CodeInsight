#include<iostream>
using namespace std;
int main() {
	long long a,b,c;
	long long ans;
	cin>>a>>b>>c;
	long long tmin = min(a,min(b,c));
	long long tmin2;
	if(a%2==0||b%2==0||c%2==0) {
		cout<<0<<endl;
	} else {
		if(tmin==a) {
			tmin2 = min(b,c);
		} else if(tmin==b) {
			tmin2 = min(a,c);
		} else {
			tmin2 = min(a,b);
		}
		cout<<tmin*tmin2;
	}

	return 0;
}