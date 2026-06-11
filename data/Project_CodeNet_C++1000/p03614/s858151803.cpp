#include <iostream>
using namespace std;

int main() {
	int n;cin>>n;
	int p[n+1];
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(p[i]==i){
			ans++;
			if(i!=n){
				p[i+1]=0;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
