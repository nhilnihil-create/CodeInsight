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
typedef long double ld;
typedef pair<int, int> pint;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tint;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<pint> vpint;
int dx[8]={0,0,-1,1,1,1,-1,-1};
int dy[8]={-1,1,0,0,1,-1,1,-1};
const int SIZE=300050;
//ここまでテンプレ
//↓Binary Indexed Tree
struct BIT{
private:
	int n;
	vector<int> node;
public:
	//N要素のBITを作り、すべて0で初期化する
	//1-indexedであることに注意！！
	BIT(int N){
		node.resize(N+1,0);
		n=N;
	}
	//ノードiまでの和を計算する
	int sum(int i){
		if(!i)
			return 0;
		return node[i]+sum(i-(i&-i));
	}
	//ノードiにxを足す
	void add(int i,int x){
		if(i>n)
			return;
		node[i]+=x;
		add(i+(i&-i),x);
	}
};
//↑Binary Indexed Tree
int main(){
	int N,M;
	cin>>N>>M;
	//x=l,y=r
	//クエリ<x,0:区間,1:質問,y>
	vector<tint> Q;
	//クエリに質問を入れていく
	for(int i=1;i<=M;i++){
		for(int j=i;j<=M;j+=i){
			int a=j-i,b=j;
			Q.eb(b,1,b);
			Q.eb(a,1,b);
		}
	}
	sort(Q.begin(),Q.end());
	Q.erase(unique(Q.begin(),Q.end()),Q.end());
	//クエリに区間を入れる
	for(int i=0;i<N;i++){
		int l,r;
		cin>>l>>r;
		Q.eb(l,0,r);
	}
	sort(Q.begin(),Q.end());
	//BIT
	BIT B(M+2);
	//クエリを処理する
	vector<unordered_map<int,int>> pam(M+2);
	for(tint T:Q){
		int a,b,c;
		tie(a,c,b)=T;
		//区間クエリなら、区間を追加する
		if(c==0){
			//S.update(b,S.getsum(b,b+1)+1);
			B.add(b+1,1);
		}
		//質問クエリなら、質問に答える
		else{
			//pam[mp(a,b)]=S.getsum(b,M+1);
			pam[a][b]=B.sum(M+1)-B.sum(b);
		}
	}
	//答えを求める
	for(int i=1;i<=M;i++){
		int ans=0;
		for(int j=i;j<=M;j+=i){
			int a=j-i,b=j;
			ans+=pam[b][b]-pam[a][b];
		}
		cout<<ans<<endl;
	}
	return 0;
}