#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n,a[100005],ans1=0,ans2=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if(a[i]==a[i+1]){
			ans1=ans2;
			ans2=a[i];
			i++;
		}
	}
	if(ans1==0){
		cout<<"0"<<endl;
	}
	else{
		cout<<ans1*ans2<<endl;
	}
  return(0);
}