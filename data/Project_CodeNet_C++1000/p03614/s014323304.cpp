#include <iostream>
using namespace std;
int main(){
	int a[100001],n;
	cin>>n;int sum=0;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		if(a[i]==i){
			int t=a[i];
			a[i]=a[i+1];
			a[i+1]=t;
			sum++;
		}
	cout<<sum<<endl;


}