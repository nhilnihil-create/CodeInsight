#include <bits/stdc++.h>

using namespace std;

int main() {
	int H,W; cin >> H >> W;
	int cnt[26]={};
	for(int i=0;i<H*W;++i) {
		char a;  cin >> a;
		++cnt[a-'a'];
	}
	int cnt4=0,cnt2=0,cnt1=0;
	for(int i=0;i<26;++i) {
		cnt4+=cnt[i]/4; cnt[i]%=4;
		cnt2+=cnt[i]/2; cnt[i]%=2;
		cnt1+=cnt[i];
	}
	bool flag=true;
	if(H%2==0&&W%2==0) {
		if(cnt2+cnt1) flag=false;
	} else if((H*W)&1) {
		cnt4-=(H/2)*(W/2);
		if(cnt4<0) flag=false;
		if(cnt2+cnt4*2<H/2+W/2) flag=false;
		if(!cnt1) flag=false;
	} else {
		if(cnt4<(H/2)*(W/2)) flag=false;
		if(cnt1) flag=false;
	}
	cout << (flag?"Yes":"No") << endl;
	
	return 0;
}
/*
偶*偶 -> 4*?
偶*奇 -> 4*((偶/2)*(奇/2)) + 2*?
奇*奇 -> 4*((奇/2)*(奇/2)) + 2*((奇/2)+(奇/2)) + 1

####
####
####
#### -> 4*4

###
###
### -> 4*1 + 2*2 + 1*1

####
####
#### -> 4*2 + 2*2

3x3 -> 4*1 + 2*2 + 1*1
3x5 -> 4*2 + 2*3 + 1*1
3x7 -> 4*3 + 2*4 + 1*1
7x5 -> 4*6 + 2*5 + 1*1
   #   
   #   
#######
   #   
   #   

 */
