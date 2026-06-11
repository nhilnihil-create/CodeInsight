#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<climits>
#include<iostream>
#include<sstream>
#include<utility>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#include<stack>
#include<functional>
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
typedef vector<vector<int>> MX;

const ll MOD=1e9+7;
const int INF = 100000000;

map<ll,ll>M;
priority_queue<ll>Q;

int main()
{
	ll N;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		int p;
		cin>>p;
		M[p]++;
	}
	for(auto p:M)
	{
		Q.push(p.second);
	}
	cout<<(Q.size()%2?Q.size():Q.size()-1)<<endl;
}
