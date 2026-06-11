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
#define INFLL 1100000000000000000LL
//#define MOD 1000000007
#define MOD 123456789012345671
#define mp make_pair
#define mt make_tuple
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pint;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tint;
typedef vector<int> vint;
typedef vector<ll> vll;
int dx[8]={0,0,-1,1,1,1,-1,-1};
int dy[8]={-1,1,0,0,1,-1,1,-1};
const int SIZE=100050;
//ここまでテンプレ
int main() {
	int N;
	cin>>N;
	int f;
	cin>>f;
	ll DP[SIZE][3]={};
	for(int i=0;i<SIZE;i++)
		for(int j=0;j<3;j++)
			DP[i][j]=-INFLL;
	DP[0][0]=f;
	for(int i=0;i<N-1;i++){
		int a;
		char o;
		cin>>o>>a;
		if(o=='+'){
			DP[i+1][0]=max(DP[i+1][0],DP[i][0]+a);
			DP[i+1][1]=max(DP[i+1][1],DP[i][1]-a);
			DP[i+1][2]=max(DP[i+1][2],DP[i][2]+a);
			DP[i+1][0]=max(DP[i+1][0],DP[i][2]+a);
			DP[i+1][0]=max(DP[i+1][0],DP[i][1]-a);
			DP[i+1][1]=max(DP[i+1][1],DP[i][2]+a);
		}
		else{
			DP[i+1][0]=max(DP[i+1][0],DP[i][0]-a);
			DP[i+1][1]=max(DP[i+1][1],DP[i][1]+a);
			DP[i+1][2]=max(DP[i+1][2],DP[i][2]-a);
			DP[i+1][1]=max(DP[i+1][1],DP[i][0]-a);
			DP[i+1][2]=max(DP[i+1][2],DP[i][1]+a);
			//DP[i+1][2]=max(DP[i+1][2],DP[i][0]-a);
		}
	}
	cout<<max({DP[N-1][0],DP[N-1][1],DP[N-1][2]})<<endl;
	/*
	for(int i=0;i<N;i++){
		for(int j=0;j<3;j++)
			printf("DP[%d][%d]=%d ",i,j,DP[i][j]);
		cout<<endl;
	}
	*/
    return 0;
}