#include<bits/stdc++.h>
using namespace std;
int a[100010];
int b[100010];
int main(){
	int n;
	while(~scanf("%d",&n)){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=0;i<n;i++){
			b[a[i]-1]++;
			b[a[i]+1]++;
			b[a[i]]++;
		}
		int max=0,h=0;
		for(int i=0;i<=100001;i++){
			if(b[i]>max){
				max=b[i];
				h=i;
			}
		}
		cout<<max<<endl;
	} 
	return 0;
} 