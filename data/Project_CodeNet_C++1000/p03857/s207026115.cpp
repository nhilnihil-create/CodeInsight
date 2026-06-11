#include <bits/stdc++.h>
#define LL long long
using namespace std;
inline int gi () {
	int x=0, w=0; char ch=0;
	while (! (ch>='0' && ch<='9') ) {
		if (ch=='-') w=1;
		ch=getchar ();
	}
	while (ch>='0' && ch<='9') {
		x= (x<<3) + (x<<1) +  (ch^48);
		ch=getchar ();
	}
	return w?-x:x;
}

const int N=2e5+10;
int n,K,L,fas[N],far[N]; 
map < pair <int , int > , int > Map;

int Get_fa (int x, int *fa) {
	return x==fa[x]?x:fa[x]=Get_fa (fa[x], fa);
}

int main ()
{
	n=gi (), K=gi (), L=gi ();
	for (int i=1;i<=n;++i) 
		fas[i]=far[i]=i;
	for (int i=1, x, y;i<=K;++i) {
		x=gi () ,y=gi ();
		int fax=Get_fa (x, fas), fay=Get_fa (y, fas);
		if (fax==fay) continue;
		fas[fax]=fay;
	}
	for (int i=1, x, y;i<=L;++i) {
		x=gi (), y=gi ();
		int fax=Get_fa (x, far), fay=Get_fa (y, far);
		if (fax==fay) continue;
		far[fax]=fay;
	}
	for (int i=1;i<=n;++i) 
		Map[make_pair (Get_fa (i, fas), Get_fa (i, far) )]++;
	for (int i=1;i<=n;++i)
		printf ("%d\n", Map[make_pair (fas[i], far[i])]);
	return 0;
}
