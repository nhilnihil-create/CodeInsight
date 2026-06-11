#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
const int SIZEN = 100010;
typedef long long LL;
LL pw[100] = {0};
int cnt = 0;
int query(LL x){
	cnt++;
	printf("? %lld\n",x);
	fflush(stdout);
	char opt[10];
	scanf("%s",opt);
	return opt[0] == 'Y';
}
int main(){
	pw[0] = 1;
	for(int i = 1;i <= 10;i++)pw[i] = pw[i-1]*10;
	int bit = 0;
	for(int i = 0;i <= 9;i++){
		int now = query(pw[i]);
		if(now == false){bit = i;break;}
	}
	if(bit == 0){
		for(int i = 0;i <= 9;i++){
			int now = query(2*pw[i]);
			if(now == true){
				printf("! %d\n",pw[i]);
				return 0;
			}
		}
		printf("! 1\n");
		return 0;
	}
	else{
		LL ans = 0;//printf("bit = %d\n",bit);
		for(int i = bit;i >= 2;i--){
			int l = 1,r = 9,mid,tmp=0;
			while(l <= r){
				mid = (l+r)>>1;
				if(query(ans*10+mid))l = mid+1,tmp = mid;
				else r = mid-1;
			}
			ans = ans*10+tmp;
		}
		if(bit == 1){
			for(int i = 1;i <= 9;i++)if(query((LL)i*pw[1])){
				printf("! %d\n",i);
				return 0;	
			}	
			printf("! 1\n");
			return 0;
		}
		for(int i = 0;i <= 9;i++){
			if(query((ans*10LL+i)*10)){
				printf("! %d\n",ans*10+i);
				return 0;
			}
		}
		printf("! %d\n",ans*10);
		return 0;
	}
	return 0;
}
