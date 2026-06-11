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
#include <unordered_map>
#include <functional>
#include <utility>
#include <tuple>
#include <cctype>
#include <bitset>
#include <complex>
#include <cmath>
#include <array>
using namespace std;
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL
#define MOD 1000000007
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pint;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tint;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<pint> vpint;
int dx[8]={0,0,-1,1,1,1,-1,-1};
int dy[8]={-1,1,0,0,1,-1,1,-1};
const int SIZE=200050;
//ここまでテンプレ
const int alpha=26;
int main(){
	string S;
	cin>>S;
	S='@'+S;
	int N=S.length();
	//DQ[i][j]=i文字目以降で最初に文字jが現れる場所(自身を含まない)
	int DQ[SIZE][alpha]={};
	for(int i=0;i<alpha;i++)
		DQ[N-1][i]=-1;
	//DP[i]=i文字目以降の部分列ではない文字列のなかで最も短いものの文字数
	int DP[SIZE]={};
	for(int i=0;i<N;i++)
		DP[i]=INF;
	DP[N-1]=1;

	//DQの遷移
	for(int i=N-2;i>=0;i--){
		for(int j=0;j<alpha;j++)
			DQ[i][j]=(S[i+1]-'a'==j?i+1:DQ[i+1][j]);
	}
	//DPの遷移
	for(int i=N-2;i>=0;i--){
		for(int j=0;j<alpha;j++)
			DP[i]=(DQ[i][j]==-1?1:min(DP[i],DP[DQ[i][j]]+1));
	}
	/*
	for(int i=0;i<N;i++){
		for(int j=0;j<alpha;j++)
			cout<<DQ[i][j]<<" ";
		cout<<endl;
	}
	for(int i=0;i<N;i++)
		cout<<DP[i]<<endl;
	*/
	//構築
	string T;
	int idx=0;
	while(1){
		//DQを見て、一番DPが小さい文字のなかで一番辞書順で小さいものに飛ぶ
		int next=-1,mini=INF;
		//-1に飛ぶとまずいので、-1が出たら別ルートに入る
		bool flag=0;
		for(int i=alpha-1;i>=0;i--){
			if(DQ[idx][i]==-1){
				flag=1;
				continue;
			}
			if(DP[DQ[idx][i]]<=mini){
				next=DQ[idx][i];
				mini=DP[next];
			}
		}
		if(flag){
			//DQが-1になるものの中で一番辞書順で小さいものをつけて終了
			for(int i=0;i<alpha;i++){
				if(DQ[idx][i]==-1){
					T+='a'+i;
					goto brk;
				}
			}
		}
		T+=S[next];
		idx=next;
	}
	brk:
	cout<<T<<endl;
	return 0;
}