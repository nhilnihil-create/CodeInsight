#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define lo long long 
#define inf 1000000000
#define md 1000000007
#define pb push_back
#define li 200005
using namespace std;
lo int x,tut;
int main(){
	scanf("%lld",&x);
	for(lo int i=1;i<=100000;i++){
		if((i*(i+1)/2)>=x){
			tut=i;
			break;
		}
	}
	printf("%lld\n",tut);
	return 0;
}
