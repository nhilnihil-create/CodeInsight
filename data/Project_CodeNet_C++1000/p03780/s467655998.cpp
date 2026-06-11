#include<iostream>
#include<algorithm>
using namespace std;
int n,k,s,a[5010],f[5010];
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		a[i]=min(a[i],k);
		s+=a[i];
	}
	sort(a,a+n+1);
	f[0]=1;
	for(int i=n;i>=0;i--){
		bool v=true;
		for(int j=k-1;j>=k-s&&j>=0;j--){
			if(f[j]){
				v=false;
			}
		}
		if(v){
			cout<<i<<endl;
			return 0;
		}
		for(int j=k;j>=a[i];j--){
			f[j]|=f[j-a[i]];
		}
		s-=a[i];
	}
	return 0;
}
