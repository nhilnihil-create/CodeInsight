#include <bits/stdc++.h>
#define X first
#define Y second
#define mp make_pair
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;

const int N = 100010;
int n,a[N];
int gcd(int a,int b){
	if(b==0) return a;
	return gcd(b,a%b);
}
int main(){
	scanf("%d",&n);
	int cnt = 0;
	bool pd =false;
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
		if(a[i]&1) {
			cnt++;
			if(a[i]>1) pd=true;
		}
	}
	int now = 1;
	while(cnt==1 && pd && (n-cnt)%2==0){
		now^=1;
		cnt = 0;
		pd = false;
		int t = a[1]>>1;
		for(int i =0;i<n;i++){
			a[i]>>=1;
			t = gcd(t,a[i]);
		}
		for(int i =0;i<n;i++) a[i]/=t;
		for(int i =0;i<n;i++){
			if(a[i]&1) {
				cnt++;
				if(a[i]>1) pd=true;
			}
		}
	}
	if(((n-cnt)&1)==now) puts("First"); else puts("Second");
	return 0;
}