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
const int SIZE=100050;
//ここまでテンプレ
int main(){
	int N,M;
	cin>>N>>M;
	vint A;
	for(int i=0;i<N;i++){
		int a;
		cin>>a;
		A.pb(a);
	}
	//ax+b
	//xの係数を格納する
	ll a[SIZE]={};
	//定数を格納する
	ll b[SIZE]={};
	for(int i=1;i<N;i++){
		int s=A[i-1],t=A[i];
		//s<t
		if(s<t){
			//s以下のところに定数を足す
			b[1]+=t-s;
			b[s+1]-=t-s;
			//s超過t以下のところに線形と定数を足す
			a[s+1]+=-1;
			a[t+1]-=-1;
			b[s+1]+=1+t;
			b[t+1]-=1+t;
			//t超過のところに定数を足す
			b[t+1]+=t-s;
		}
		//t<s
		else{
			//t以下のところに線形と定数を足す
			a[1]+=-1;
			a[t+1]-=-1;
			b[1]+=1+t;
			b[t+1]-=1+t;
			//t超過s以下のところに定数を足す
			b[t+1]+=M-s+t;
			b[s+1]-=M-s+t;
			//s超過のところに線形と定数を足す
			a[s+1]+=-1;
			b[s+1]+=1+M+t;
		}
	}
	//累積和を取る
	for(int i=1;i<SIZE;i++){
		a[i]+=a[i-1];
		b[i]+=b[i-1];
	}
	//線形をx倍する
	for(int i=0;i<SIZE;i++)
		a[i]*=i;
	ll ans=INFLL;
	for(int i=1;i<=M;i++)
		ans=min(ans,a[i]+b[i]);
	cout<<ans<<endl;
	return 0;
}