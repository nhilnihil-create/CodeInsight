#include <iostream>
using namespace std;

int main() {
	long long x;cin>>x;
	long long temp=0;
	long long ans=0;
	for(long long i=0;i<=x;i++){
		temp+=i;
		if(temp>=x){
			ans=i;
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}
