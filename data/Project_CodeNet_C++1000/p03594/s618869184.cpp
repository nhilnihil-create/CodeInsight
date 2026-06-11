#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define sd(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define pd(n) printf("%d",n)
#define pl(n) printf("%lld",n)
#define sf(n) scanf("%f",&n)
#define pf(n) printf("%.12f",n)
#define psp printf(" ")
#define endc printf("\n")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const int maxn = 520;


int main() {
	IOS;; string s = "RYGB";
	int h,w,d; cin>>h>>w>>d;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			int a = i+j, b = i-j;
			a/=d; b=floor(b*1.0/d); a%=2; b=abs(b)%2;
			//cout<<i<<":"<<j<<" -> "<<a<<":"<<b<<endl;
			cout<<s[a*2 + b];
		}
		cout<<endl;
	}
}