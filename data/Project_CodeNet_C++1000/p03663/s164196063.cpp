#include<bits/stdc++.h>
using namespace std;

char s[12] = "99999999999", c[12];
long long ans, n, l, r, mid, flag = 1;

int main(){
	for (int i=0; i<=9; i++){
		l = (i == 0); r = 9;
		while (l < r){
			mid = l + r >> 1;
			s[i] = mid + '0';
			printf("? %s\n", s);
			fflush(stdout); scanf("%s", &c);
			if (c[0] == 'Y') r = mid;
			else l = mid + 1;
		}
		ans = ans * 10 + l;
		printf("? %I64d\n", ans+1);
		fflush(stdout); scanf("%s", &c);
		if (l != 9) flag = 0;
		if (flag && c[0] == 'N' || !flag && c[0] =='Y'){
			printf("! %I64d\n", ans); 
			fflush(stdout); return 0;
		}
		s[i] = l + '0';
	}
	return 0;
}