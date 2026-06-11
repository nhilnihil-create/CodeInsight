#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define piii pair<int,pii>
#define pll pair<ll,ll>
#define plii pair<ll,pii>
#define vi vector<int>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define SORT(x) sort(x.begin(), x.end())
#define GSORT(x) sort(x.begin(), x.end(), greater<int>())
#define mx 100001
#define eps 0.00000000001
#define mod 1000000007
#define pi acos(-1)
#define inf 100000000
#define loop(i,b,n) for(int i=b;i<n;++i)
#define rev_loop(i,b,n) for(int i=b;i>=n;--i)
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int main()
{
    fio;
    int n,m,x,y;
    cin>>n>>m;
    int a1[n+1]={0};
	int a2[n+1]={0};
	bool chk=false;
	loop(i,0,m){
		cin>>x>>y;
		if(x==1) a1[y]=1;
		if(y==n) a2[x]=1;
		if(a1[x] && a2[x])
            chk = true;
		if(a1[y] && a2[y])
		 chk =true;
	}
    if(chk)
    cout<<"POSSIBLE";
	else
	cout<<"IMPOSSIBLE";
    return 0;
}
