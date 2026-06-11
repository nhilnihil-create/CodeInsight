#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define COIN const int
#define ite iterator
#define PII pair<int,int>
#define PSI pair<string,int>
#define PIS pair<int,string>

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REPD(i,n) for((i)=(n)-1;(i)>=0;(i)--)

#define ALL(c) (c).begin(), (c).end()
#define sz(s) (s).size()
#define CLEAR(x) memset(x,0,sizeof x);

#define MP make_pair
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define X first
#define Y second

#define VI vector<int>
#define VS vector<string>
#define VII vector<PII>
#define VVI vector<VI>

#define PIII 3.1415926
#define PI 3.14
/*****************************************************************************/

using namespace std;

ll res=1,n,m,mod=1e9+7;
bool pri[1001];
long long f(int x){
	m=n;
	int cnt=0;
	while(m)
		cnt+=m/x,m/=x;
	return cnt;
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin>>n;
	memset(pri,1,sizeof pri);
	pri[0]=pri[1]=0;
	for(int i=2;i<=n;i++)
		if(pri[i])
			for(int j=2;j*i<=n;j++)
				pri[j*i]=0;
	for(int i=1;i<=n;i++) {
		if(pri[i]) {
			res=(res*(f(i)+1))%mod; 
		}
	}
	cout<<res<<endl;
	return 0;
}
/******************************************************************************
1000
972926972

972926972
******************************************************************************/

