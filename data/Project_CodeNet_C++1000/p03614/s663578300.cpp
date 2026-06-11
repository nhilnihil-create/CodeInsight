#include<iostream>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<cstdio>
#include<utility>
#include<algorithm>



int main(void){
	int n;
	int m1;
	int answer=0;
	std::vector<int> num(100000);
	scanf("%d",&n);
	for(int lp=0;lp<n;lp++){
		scanf("%d",&num[lp]);
		num[lp]--;
	}

	int at1=0;
	bool frag=false;
	for(at1=0;at1<n;at1++){
		if(num[at1]==at1){
			at1++;
			answer++;
		}
	}
	std::cout<<answer<<std::endl;
	return 0;
}
