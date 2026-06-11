#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=200005;
int n,L,T,p=0,res[N];
int main(){
	cin >> n >> L >> T;
	for (int i=0,x,w;i<n;i++){
		cin >> x >> w;
		if (w==1)
			res[i]=(x+T)%L,p=(p+(T+x)/L%n+n)%n;
		else
			res[i]=((x-T)%L+L)%L,p=(p-(T+L-x-1)/L%n+n)%n;
	}
	sort(res,res+n);
	for (int i=0;i<n;i++,p=(p+1)%n)
		printf("%d\n",res[p]);
	return 0;
}