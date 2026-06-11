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

int main()
{
	int N,M,K;
	bool ok=false;
	cin>>N>>M>>K;
	for(int i=0;i<=N;i++)
	{
		int cnt=i*M;
		for(int j=0;j<=M;j++)
		{
			cnt=cnt-i+(N-i);
			if(cnt==K)ok=true;
		}
	}
	cout<<(ok?"Yes":"No")<<endl;
}
