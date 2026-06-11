#include<bits/stdc++.h>
using namespace std;
#define N 100010
int n,a[N];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		if(i+1>a[i+1]){
			int j=0;
			while(a[j+i+1]==i)j++;
			if(((a[i]-i)&1)||(j&1))puts("First");
			else puts("Second");
			exit(0);
		}
}