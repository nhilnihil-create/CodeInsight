#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const int N = 1e5;
LL enter_count[N+1];
LL exit_count[N+1];
LL exit_len[N+1];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	memset(enter_count,0,sizeof enter_count);
	memset(exit_count,0,sizeof exit_count);
	memset(exit_len,0,sizeof exit_len);

	int n, m; cin >> n >> m;
	int u; cin >> u;
	LL honest = 0;

	LL curr_count = 0, curr_len = 0;
	for(int i = 0; i < n-1; i++)
	{
		int v; cin >> v;
		enter_count[u]++;
		exit_count[v]++;
		LL len = (v-u+m)%m;
		exit_len[v] += len;
		honest += len;

		if(u > v) //initialize curr_count to when favorite is placed at 1
		{
			curr_count++;
			curr_len += m-u+1;
		}
		u = v;
	}

	LL savings = curr_len-curr_count;
	for(int i = 2; i <= m; i++)
	{
		curr_count += enter_count[i-1]; //all guys who begin at i-1 begin getting bonuses now
		curr_count -= exit_count[i-1];  //all guys who end at i-1 stop getting bonuses now
		curr_len -= exit_len[i-1];      //remove the bonuses from the guys we killed
		curr_len += curr_count;  	    //everyone alive gets a +1 bonus as we move from i-1 to i
		savings = max(savings,curr_len-curr_count);
	}
	cout<<honest-savings<<endl;
	return 0;
}