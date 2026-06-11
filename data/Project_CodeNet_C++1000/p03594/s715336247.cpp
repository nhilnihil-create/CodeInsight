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
#include<tuple>
#define rep(index,num) for(int index=0;index<num;index++)
#define rep1(index,num) for(int index=1;index<=num;index++)
#define scan(argument) cin>>argument
#define prin(argument) cout<<argument<<endl
#define kaigyo cout<<endl
#define eps 1e-15
#define mp(a1,a2) make_pair(a1,a2)
#define YMAX 250001
typedef long long ll;
using namespace std;
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<pint> vpint;
typedef vector<pll> vpll;
ll INFl=1e+18+1;
int INF=1e+9+1;
int main(){
	int H,W,d;
	char m[4]={'R','Y','G','B'};
	scan(H);scan(W);scan(d);
	if(d%2==0){
		rep(i,H){
			rep(j,W){
				int clustnum=(i+j)/d%2;
				int colornum=(j-i+H+W)/d%2;
				printf("%c",m[clustnum*2+colornum]);
			}
			kaigyo;
		}
	}
	else{
		rep(i,H){
			rep(j,W){
				printf("%c",m[(i+j)%4]);
			}
			kaigyo;
		}
	}
	return 0;
}
