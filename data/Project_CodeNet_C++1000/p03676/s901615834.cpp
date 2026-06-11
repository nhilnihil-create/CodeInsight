#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define MOD 1000000007
#define Long long long 
using namespace std;
#define maxn 100002
int a[maxn];
bool dau[maxn];
Long C1[maxn],C2[maxn];
Long power(Long b, Long p, Long mod){
	if(p==1) return b;
	Long temp = power(b,p/2,mod);
	if(p%2==0) return (temp*temp)%mod;
	return ((temp*temp)%mod*b)%mod;
}
Long divide(Long a, Long b,Long mod){
// 	if(a*(power(b,mod-2,mod)) <0 ) cout <<"!!!" << a;
	return (a*(power(b,mod-2,mod)))%mod;
}
void CalCkn(Long n, Long* C, Long mod){
	C[0] = 1;
	For(i,1,n){
		C[i] = divide(((n-i+1)*C[i-1])%mod,i,mod);
	}	
}
main(){
	Long n;
	cin >> n;
	Long pos1=0;
	Long pos2  = 0;
	Long num = 0;
	For(i,1,n+1)	 {
		scanf("%d",a+i);
		if(dau[a[i]]){
			num = a[i];
		}	else	{
			dau[a[i]] = true;
		}
	}
	For(i,1,n+1){
		if(a[i]==num){
			if(pos1==0)		{
				pos1=i;
			}	else	{
				pos2 = i;
			}
		}
	}
	Long apc = pos1-1 + (n+1-pos2);
	CalCkn(n+1,C1,MOD);
	CalCkn(apc,C2,MOD);
//	For(i,0,n+1){
//		cout << C1[i]<< " ";
//	}
	Long ans= 0;
	For(i,1,n+1){
		ans = C1[i];
		if(i-1<=apc) ans -= C2[i-1];
		ans+= MOD;
		ans %= MOD;
		printf("%lld\n",ans);
	}
}