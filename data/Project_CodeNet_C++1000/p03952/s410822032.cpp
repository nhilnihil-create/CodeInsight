#include <iostream>
#include <cstring>
#define MOD 1000000007
using namespace std;

int n, x, arr[200010], k[200010];

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>x;
	if(x==1||x==2*n-1){
		cout<<"No";
		return 0;
	}
	if(n==2){
		if(x==1||x==3){
			cout<<"No";
			return 0;
		}
		cout<<"Yes"<<endl<<1<<endl<<2<<endl<<3<<endl;
		return 0;
	}
	arr[n]=x;
	k[x]=1;
	if(x<3){
		arr[n-1]=x-1;
		arr[n+1]=x+1;
		arr[n-2]=x+2;
		k[x-1]=1;
		k[x+1]=1;
		k[x+2]=1;
	}else{
		arr[n-1]=x-1;
		arr[n+1]=x+1;
		arr[n+2]=x-2;
		k[x-1]=1;
		k[x+1]=1;
		k[x-2]=1;
	}

	int j=1;
	for (int i = 1; i <= 2*n-1; ++i){
		if(!arr[i]){
			while(k[j])j++;
			arr[i]=j;
			k[j]=1;
			j++;
		}
	}
	cout<<"Yes"<<endl;
	for (int i = 1; i <= 2*n-1; ++i){
		cout<<arr[i]<<endl;
	}
	return 0;
}