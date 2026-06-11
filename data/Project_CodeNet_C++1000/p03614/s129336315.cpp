#include <iostream>
using namespace std;
const int maxn=1e5+10;
int a[maxn];
int main(int argc, char *argv[])
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	  cin>>a[i];
	 int sum=0; 
	for(int i=0;i<n;i++){
		if(a[i]==i+1){
			int t=a[i];
			a[i]=a[i+1];
			a[i+1]=t;
			sum++;
		}
	}  
	for(int i=n-1;i>=0;i--){
		if(a[i]==i+1){
			int t=a[i];
			a[i]=a[i+1];
			a[i+1]=t;
			sum++;
		}
	}  
	cout<<sum<<endl;
	return 0;
}