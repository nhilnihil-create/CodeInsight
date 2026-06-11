#include <bits/stdc++.h>
using namespace std;
#define LL long long
const double epsilon=double(1e-9);
int main(int argc,char *argv[]){
	if(argc>=2){freopen(argv[1],"r",stdin);}
	if(argc>=3){freopen(argv[2],"w",stdout);}
	
	LL x;cin>>x;
	LL y=(LL)((sqrt(x*8+1)-1)/2+epsilon);
	if((y+1)*y/2<x)++y;
	cout<<y;
	fclose(stdin);fclose(stdout);
	return 0;
}
