#include <iostream>
using namespace std;
int main(){
	int n,t=0;
	cin>>n;
	int l[n+1],r[n+1];
	for(int i=1;i<=n;i++){
		cin>>l[i]>>r[i];
		t+=r[i]-l[i]+1;
	}
	cout<<t<<endl;
	return 0;
}