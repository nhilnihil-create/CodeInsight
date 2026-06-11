#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
const int MAXN = 100005;
const int mod = 998244353;

bool query(lint x){
	printf("? %lld\n", x);
	fflush(stdout);
	char str[10]; cin >> str;
	return *str == 'Y';
}

int main(){
	if(query(1e10)){
		lint cur = 9;
		for(int i=1; ; i++){
			if(query(cur) == 1){
				printf("! %lld\n", (cur + 1) / 10);
				return 0;
			}
			cur = cur * 10 + 9;
		}
	}
	lint pwr = 1;
	for(int i=0; ; i++){
		if(!query(pwr)){
			lint s, e;
			s = pwr / 10;
			e = pwr - 1;
			while(s != e){
				lint m = (s + e) / 2;
				if(query(1000000 * m + 696969) == 0){
					s = m + 1;
				}
				else e = m;
				
			}
			printf("! %lld\n", s);
			return 0;
		}
		pwr *= 10;
	}
}
