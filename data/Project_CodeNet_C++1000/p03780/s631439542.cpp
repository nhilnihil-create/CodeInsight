#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<map>
#include<iomanip>
#include<set>
#include<bitset>
#define rep(index,num) for(int index=0;index<num;index++)
#define rep1(index,num) for(int index=1;index<=num;index++)
#define brep(index,num) for(int index=num-1;index>=0;index--)
#define brep1(index,num) for(int index=num;index>0;index--)
#define scan(argument) cin>>argument
#define prin(argument) cout<<argument<<endl
#define kaigyo cout<<endl
#define eps 1e-7
#define mp(a1,a2) make_pair(a1,a2)
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef long double ld;
using namespace std;
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<pint> vpint;
typedef vector<pll> vpll;
ll INFl=1e+18+1;
int INF=1e+9+1;
bool ldp[5001][5001],rdp[5001][5001];
int main(){
	int N,K;
	ll a[5001];
	vll sa;
	scan(N>>K);
	int ans=N;
	rep(i,N){
		scan(a[i]);
		if(a[i]>K) ans--;
		else sa.push_back(a[i]);
	}
	sort(ALL(sa));
	int M=sa.size();
	ldp[0][0]=1;
	rep(i,M){
		rep(k,K+1){
			ldp[i+1][k]|=ldp[i][k];
			if(k>=sa[i]) ldp[i+1][k]|=ldp[i][k-sa[i]];
		}
	}
	rdp[M][0]=1;
	brep1(i,M){
		rep(k,K+1){
			rdp[i-1][k]|=rdp[i][k];
			if(k>=sa[i-1]) rdp[i-1][k]|=rdp[i][k-sa[i-1]];
		}
	}
	rep(i,M){
		/*printf("i:%d sa[i]:%d\nldp: ",i,sa[i]);
		rep(k,K+1) printf("%d ",ldp[i][k]);
		printf("\nrdp: ");
		rep(k,K+1) printf("%d ",rdp[i+1][k]);
		kaigyo;*/
		int rkosu[5002]={};
		rep(j,5001){
			rkosu[j+1]=rkosu[j]+rdp[i+1][j];
		}
		int flag=1;
		rep(j,K){
			if(ldp[i][j]){
				if(K-j-sa[i]<0){
					if(rkosu[K-j]>0){
						flag=0;
						//printf("i:%d sa[i]:%d j:%d flag0\n",i,sa[i],j);
						break;
					}
				}
				else if(rkosu[K-j]!=rkosu[K-j-sa[i]]){
					flag=0;//hituyo
					//printf("i:%d sa[i]:%d j:%d flag00\n",i,sa[i],j);
					break;
				}
			}
		}
		if(flag==0) ans--;
		//printf("i:%d sa[i]:%d flag:%d\n",i,sa[i],flag);
	}
	/*rep(i,M){
		bitset<5001> dp[];
		dp.set(0);
		rep(j,M){
			if(j==i) continue;
			dp|=(dp<<sa[j]);
		}
		int flag=1;
		for(int k=K-sa[i];k<K;k++){
			if(dp[k]){
				flag=0;
				break;
			}
		}
		if(flag==0) ans--;
	}*/
	prin(ans);
	return 0;
}
