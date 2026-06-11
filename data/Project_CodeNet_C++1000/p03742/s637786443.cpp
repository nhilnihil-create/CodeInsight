#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <stack>
#include <set>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P2;
const int inf=1000000000;
int dp[101][101][301]={};
ll w1[101]={};
int v1[101]={};
ll km[101]={};
int main() {
	ll x,y;
	cin>>x>>y;
	if(abs(x-y)<=1){
		cout<<"Brown"<<endl;
	}else{
		cout<<"Alice"<<endl;
	}
	return 0;
}
