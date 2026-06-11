
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<functional>
#include<algorithm>
#include<stack>
#include<queue>
#include<iomanip>
#include<set>
#include<map>
#include<utility>
#include<string>
#include<vector>

using namespace std;

#define LL long long
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
bool IA(int x, int y, int H, int W) { return (0<=x && x<=H) && (0<=y && y<=W); }

LL N,K,a[15],sum=(1ll<<60);

int main(){
	cin>>N>>K;
	for(int i=0;i<N;i++)cin>>a[i];

	for(int b=1;b<(1<<N);b++){
		LL tmp=0ll,hi=0ll,on=0ll;
		for(int d=0;d<15;d++)if(b&(1<<d))on++;
		if(on<K)continue;
		for(int i=0;i<N;i++){
			if(i){
				hi=max(hi,a[i-1]);
				if((b&(1<<i)) && hi>=a[i]){
					hi++;
					tmp+=hi-a[i];
				}
			}
		}
		sum=min(sum,tmp);
	}
	cout<<sum<<endl;
	return 0;
}
