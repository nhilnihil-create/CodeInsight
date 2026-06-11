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

vector<ll>X;

int main()
{
	ll N,A,B;
	cin>>N>>A>>B;
	for(int i=0;i<N;i++)
	{
		ll a;
		cin>>a;
		X.push_back(a);
	}
	vector<ll>C(N,0);
	for(int i=1;i<N;i++)
	{
		C[i]=C[i-1]+min((X[i]-X[i-1])*A,B);
	}
	cout<<C[N-1]<<endl;
}
