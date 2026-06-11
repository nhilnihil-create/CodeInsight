#include <iostream>
#include <cstdio>

using namespace std;

const int P=1000000007;
const int N=1000005;

int f[N],tag[N];
int n;

inline void update(int &x,int y){(x+=y)%=P;}

void dp()
{
	f[1]=1;
	for (int i=1,cur=0;i<=n+1;++i)
	{
		update(cur,tag[i]),update(f[i],cur);
		if (i>n) continue;
		if (i==n) update(f[n+1],1ll*f[n]*n%P);
		else
		{
			update(f[i+1],f[i]);//put an one in this blank
			/*put an number x(x>1) in this place and put x ones in the following blanks*/
			if (i+2<=n) update(tag[i+3],f[i]),update(tag[n+1],P-f[i]),update(f[n+1],1ll*(i+1)*f[i]%P);
			else update(f[n+1],1ll*f[i]*(n-1)%P);
			/*put an number x(x>1) in this place and put infinity non-ones in the following blanks*/
			update(f[n+1],1ll*f[i]*(n-1)%P*(n-1)%P);
		}
	}
}

int main()
{
	//freopen("neutral.in","r",stdin),freopen("neutral.out","w",stdout);
	scanf("%d",&n),dp(),printf("%d\n",f[n+1]);
	//fclose(stdin),fclose(stdout);
	return 0;
}