#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+3;
int n,a[N];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=n;i++){
		if(i+1>a[i+1]){
			int j=0;
			for(;a[j+i+1]==i;++j);
			if((a[i]-i)&1||(j&1))puts("First");
			else puts("Second");
			break;
		}
	}
}