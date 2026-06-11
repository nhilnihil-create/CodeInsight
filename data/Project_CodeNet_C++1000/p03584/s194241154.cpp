// http://tenka1-2017.contest.atcoder.jp/submissions/1715227
 
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <utility>
#include <tuple>
#include <cctype>
using namespace std;
#define INF 0x3f3f3f3f
//#define INF 1100000000000000000LL
#define MOD 1000000007
#define mp make_pair
#define mt make_tuple
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pint;
typedef vector<int> vint;
typedef vector<ll> vll;
int dx[8]={0,0,-1,1,1,1,-1,-1};
int dy[8]={-1,1,0,0,1,-1,1,-1};
const int SIZE=1050;
//int arr[SIZE]={};
//ここまでテンプレ
int main(){
	int N,K;
	cin>>N>>K;
	vint A,B;
	for(int i=0;i<N;i++){
		int a,b;
		cin>>a>>b;
		A.pb(a);
		B.pb(b);
	}
	bool bit[32]={};
	for(int i=0;i<32;i++){
		bit[i]=(K>>i&1);
	}
	ll ans=0,sum=0;
	for(int i=0;i<N;i++){
		bool flag=0;
		for(int j=0;j<32;j++){
			if(!bit[j] && bit[j]!=(A[i]&(1<<j)))
				flag=1;
		}
		if(!flag)
			sum+=B[i];
	}
	ans=sum;
	for(int i=0;i<32;i++){
		if(bit[i]){
			sum=0;
			for(int j=0;j<N;j++){
				bool flag=0;
				for(int k=31;k>=0;k--){
					if(k<i){
					}
					else if(k==i){
						if(A[j]&(1<<k))
							flag=1;
					}
					else{
						if(!bit[k] && bit[k]!=(A[j]&(1<<k)))
							flag=1;
					}
				}
				if(!flag){
					sum+=B[j];
				}
			}
			ans=max(ans,sum);
		}
	}
	cout<<ans<<endl;
	return 0;
}