#include<bits/stdc++.h>

constexpr auto MAXN = 400000+50;

int totNums,totLine,num[MAXN]; bool val[MAXN];

bool Check(const int& targ){
	for(int i=0;i<totNums;i++) val[i] = num[i]>=targ;

	for(int i=totLine;i<totNums;i++)
		if(val[i] == val[i-1]) return val[i];
		else if(val[totNums-i] == val[totNums-i-1]) return val[totNums-i];
	return *val;
}

signed main(void)
{
	int fr = INT_MAX, to = INT_MIN,mid;

	scanf("%d", &totLine); totNums = (totLine<<1)-1;
	for(int i=0;i<totNums;i++){ scanf("%d", num+i); fr = std::min(fr,num[i]); to = std::max(to,num[i]); }

	while(fr<to){
		mid = (1+fr+to)>>1;
		if(Check(mid)) fr = mid;
		else to = mid-1;
	}

	printf("%d\n", fr);

	return 0;
}