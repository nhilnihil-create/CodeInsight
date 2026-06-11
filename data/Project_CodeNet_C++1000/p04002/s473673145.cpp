#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <stack>
#include <set>
#include <cstdio>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P2;
const int inf=1000000000;

int main() {
	int n;
	ll h,w;
	cin>>h>>w>>n;

	vector<P> a;
	ll dp[10]={};
	dp[0]=(h-2)*(w-2);

	P ab[100001];
	for(int i=0;i<n;++i)cin>>ab[i].first>>ab[i].second;
	sort(ab,ab+n);
	for(int i=0;i<n;++i){
		int a1=ab[i].first;
		int b1=ab[i].second;
		int d[5][5]={};
		if(a1==2){
			for(int i=0;i<5;++i)d[0][i]=10;
		}
		if(a1==1){
			for(int i=0;i<5;++i)d[0][i]=10;
			for(int i=0;i<5;++i)d[1][i]=10;
		}
		if(a1==(h-1)){
			for(int i=0;i<5;++i)d[4][i]=10;
		}
		if(a1==h){
			for(int i=0;i<5;++i)d[3][i]=10;
			for(int i=0;i<5;++i)d[4][i]=10;
		}
		if(b1==2){
			for(int i=0;i<5;++i)d[i][0]=10;
		}
		if(b1==1){
			for(int i=0;i<5;++i)d[i][0]=10;
			for(int i=0;i<5;++i)d[i][1]=10;
		}
		if(b1==(w-1)){
			for(int i=0;i<5;++i)d[i][4]=10;
		}
		if(b1==w){
			for(int i=0;i<5;++i)d[i][3]=10;
			for(int i=0;i<5;++i)d[i][4]=10;
		}



		int flg=a.size();
		while(flg>0){
			flg--;
			int a2=a[flg].first;
			int b2=a[flg].second;
			if((a2>=(a1-2))&&(((b2-2)<=b1)&&((b2+2)>=b1))){
				d[a2-a1+2][b2-b1+2]=1;
			}
			if(b2<b1-2){
				flg=upper_bound(a.begin(),a.end(),P(a2-1,b1+2))-a.begin();
			}
			if(a2<a1-2)break;
		}
		a.push_back(P(a1,b1));
		d[2][2]=1;

//		for(int j1=0;j1<5;++j1){
//			for(int j2=0;j2<5;++j2){
//				cout<<d[j1][j2]<<" ";
//			}
//			cout<<endl;
//		}

		for(int j1=0;j1<3;++j1){
			for(int j2=0;j2<3;++j2){
				int t=0;
				for(int j3=0;j3<3;++j3){
					for(int j4=0;j4<3;++j4){
						t+=d[j1+j3][j2+j4];
					}
				}
				if(t<10){
					dp[t]++;
					dp[t-1]--;
				}
			}
		}
//		cout<<dp[0]<<endl;
	}
	for(int i=0;i<10;++i)cout<<dp[i]<<endl;
	return 0;
}
