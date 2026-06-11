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
	vector<pint> vec;
	int W,H;
	cin>>W>>H;
	for(int i=0;i<W;i++){
		int p;
		cin>>p;
		vec.pb(mp(p,0));
	}
	for(int i=0;i<H;i++){
		int	q;
		cin>>q;
		vec.pb(mp(q,1));
	}
	sort(vec.begin(),vec.end());
	ll a=W+1,b=H+1;
	ll ans=0;
	for(pint now:vec){
		if(!now.second && b>0){
			ans+=b*now.first;
			a--;
		}
		else if(now.second && a>0){
			ans+=a*now.first;
			b--;
		}
	}
	cout<<ans<<endl;
	return 0;
}