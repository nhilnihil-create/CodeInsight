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
	//最初の質問
	cout<<"? "<<1000000000<<endl;
	//最初の入力
	string F;
	cin>>F;
	//10のべき
	if(F=="Y"){
		int Q=2;
		for(int i=0;i<10;i++){
			cout<<"? "<<Q<<endl;
			string A;
			cin>>A;
			if(A=="Y"){
				cout<<"! "<<Q/2<<endl;
				return 0;
			}
			Q*=10;
		}
	}
	//10のべきでない
	//桁数を決める
	else{
		int d=0;
		int Q=100000000;
		for(int i=0;i<10;i++){
			cout<<"? "<<Q<<endl;
			string A;
			cin>>A;
			if(A=="Y"){
				d=8-i;
				break;
			}
			Q/=10;
		}
		//二分探索
		//equalは
		ll low=1,high=1;
		for(int i=0;i<d;i++)
			low*=10;
		high=low*10;
		while(high-low>1){
			ll mid=(high+low)/2;
			cout<<"? "<<mid*10<<endl;
			string A;
			cin>>A;
			if(A=="N")
				low=mid;
			else
				high=mid;
		}
		cout<<"! "<<high<<endl;
	}
	return 0;
}