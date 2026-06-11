#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	vector<int>a(11,-1);
	int x;
	for(int i=0;i<k;i++){
		cin>>x;
		a[x]++;
	}
	for(int i=n;i;i++){
		int temp=i;
		int flag=0;
		while(temp>0){
			int d=temp%10;
			temp/=10;
			if(a[d]==0){
				flag=1;
				break;
			}
		}
		if(flag)continue;
		cout<<i;
		break;
	}
  
	return 0;
}
