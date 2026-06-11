#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
	int n,a[100000],i,c=0;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];	
	}
	for(i=1;i<=n;i++){
		if(a[i]==i){
		int t=a[i];
			a[i]=a[i+1];
			a[i+1]=t;
			c++;		
		}
	if(a[i]==i&&i==n){
		int t=a[i];
			a[i]=a[i-1];
			a[i-1]=t;
			c++;		
		}	
	}
	cout<<c<<endl;
    //code:尧雷
	return 0;
}
