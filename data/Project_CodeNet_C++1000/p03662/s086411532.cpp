#include <bits/stdc++.h>

using namespace std;

#define REP(i,n)	for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,s,n)	for(int i=(s), i##_len=(n); i<i##_len; ++i)

#define ALL(obj)	(obj).begin(),(obj).end()

typedef unsigned int 			uint;
typedef unsigned long long int	ull;
typedef long long int 			ll;

typedef pair<int,int>			P;

#define LINF		((ll)1 << 63 -1)
#define INF 		2000000007
#define MINF		-2000000007
#define MAX 		100005

const int MOD = 1e9+7;
// テンプレ終了
//====================================================================//

vector<vector<int>> edge(MAX);
int used[MAX];
//
int main(){
	int N;cin>>N;
	REP(i,N-1){
		int a,b;
		cin>>a>>b;--a;--b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	queue<int> fe[2];
	fe[0].push(0),fe[0].push(-1);
	fe[1].push(N-1),fe[1].push(-1);
	used[0]=1;used[N-1]=2;

	while(!fe[0].empty() || !fe[1].empty()){
		REP(i,2){
			if(fe[i].empty())continue;
			int f = fe[i].front();fe[i].pop();
			while(f != -1){
				for(int itr : edge[f]){
					if(used[itr]!=0)continue;
					fe[i].push(itr);
					used[itr]=i+1;
				}
				f = fe[i].front();fe[i].pop();
			}
			if(!fe[i].empty())fe[i].push(-1);
		}
	}

	int FenCnt=0;
	REP(i,N)if(used[i]==1)FenCnt++;

	cout << ((N/2)<FenCnt ? "Fennec" : "Snuke") << endl;


	return 0;
}


