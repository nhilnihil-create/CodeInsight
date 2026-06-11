#include<bits/stdc++.h>
using namespace std;
int n,pos,a[100005];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	for (int i=1;i<=n+1;i++)
		if (a[i+1]<=i){
			pos=i-1; break;
		}
	int t1=a[pos+1]-pos,t2;
	for (int i=1;i<=n;i++)
		if (a[i+1]<=pos){
			t2=i-pos;
			break;
		}
	if (t1%2==0||t2%2==0)
		puts("First");
	else puts("Second");
}