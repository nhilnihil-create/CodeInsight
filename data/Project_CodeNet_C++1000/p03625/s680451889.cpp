#include <bits/stdc++.h>
using namespace std;
long long a[100010],n,sisi1,sisi2;
int main() {
cin>>n;
for(int i=1;i<=n;i++) {
	cin>>a[i];
}
sort(a+1,a+n+1);
for(int i=n;i>=2;i--) {
	if(a[i]==a[i-1]) {
		sisi1=i;
		break;
	}
}
//for(int i=n;i>=2;i--) {
//	if(a[i]==a[i-1]) {
//		sisi1=a[i];      //kalo yang ini jadi runtime gatau kenapa
//		break;
//	}
//}      
for(int i=sisi1-2;i>=2;i--) {
	if(a[i]==a[i-1]) {
		sisi2=i;
		break;
	}
}
cout<<a[sisi1]*a[sisi2]<<endl;
}