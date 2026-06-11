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
#include <numeric>
using namespace std;
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL
//#define MOD 998244353
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
const int SIZE=350;
//↑templete
#define int long long
signed main(){
	int N, T;
	cin>>N>>T;
	vll A;
	for(int i=0;i<N;i++){
		int a;
		cin>>a;
		A.pb(a);
	}

	int mini=INF, ans=0;
	for(int i=0;i<N;i++){
		ans=max(ans, A[i]-mini);
		mini=min(mini, A[i]);
	}

	mini=INF;
	int cost=0;
	for(int i=0;i<N;i++){
		int temp=A[i]-mini;
		if(temp>=ans){
			cost+=temp-ans+1;
			A[i]-=temp-ans+1;
		}
		mini=min(mini, A[i]);
	}
	cout<<cost<<endl;
	return 0;
}

