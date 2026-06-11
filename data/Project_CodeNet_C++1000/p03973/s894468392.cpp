#include <iostream>
#include<vector>
using namespace std;

int main() {
	int n;cin>>n;
	vector<int> a(n);
//	vector<int> p(n,1);
	int p=1;
	long long ans=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i){
			if(p+1==a[i]){
				p++;
			}else{
				ans+=(a[i]-1)/(p+1);
			}
		}else{
			ans+=a[i]-1;
		}
	}
	cout<<ans<<endl;


	return 0;
}
