#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=100005;
const ll inf=1e18;

void gi(int&x){static char c;for(c=getchar();c<'0'||c>'9';c=getchar());for(x=0;c<='9'&&c>='0';c=getchar())x=x*10+(c&15);}
void gc(char&c){for(c=getchar();c!='+'&&c!='-';c=getchar());}

int n,a[N];
char op[N];
ll f0,f1,f2;

int main(){
	gi(n),gi(a[0]);
	for(int i=1;i<n;i++)gc(op[i]),gi(a[i]);
	f0=a[0],f1=f2=-inf;
	for(int i=1;i<n;i++){
		if(op[i]=='-'){
			f2-=a[i],f1+=a[i],f0-=a[i];
			if(f1>f2)f2=f1;if(f0>f1)f1=f0;
		}else f2+=a[i],f1-=a[i],f0+=a[i];
		if(f2>f1)f1=f2;if(f1>f0)f0=f1; 
	}
	printf("%lld\n",f0);
	return 0;
}