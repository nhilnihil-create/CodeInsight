/*
{By GWj

*/
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int n;
int a[100000+20];

int main(){
	fastio;
	R(n);
	rb(i,1,n) R(a[i]);
	sort(a+1,a+1+n);
	int las=0;
	LL sum=0;
	while(1){
		int index=las+1;
		sum+=a[las+1];
		while(index!=n&&sum*2>=a[index+1]){
			index++;
			sum+=a[index];
		}
		if(index==n){
			cout<<n-las<<endl;break;
			
		}
		las=index;	
	}
	return 0;
}