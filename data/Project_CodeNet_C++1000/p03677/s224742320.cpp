/*
AuThOr Gwj
*/
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
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define debug_pair(A) cerr<<A.FIR<<" "<<A.SEC<<endl;
#define biggest(A,B) A=max(A,B)
#define smallest(A,B) A=min(A,B)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,m,a[100000+2];
LL cf[100008],ccf[100008];
int main(){
	fastio;
	cin>>n>>m;
	rb(i,1,n){
		cin>>a[i];
	}
	LL res=0;
	rb(i,2,n){
		if(a[i]==a[i-1]) continue;
		if(a[i-1]<a[i]){
			res+=a[i]-a[i-1];
			if(a[i]-a[i-1]>=2){
				ccf[a[i-1]+2]++;
				ccf[a[i]+1]--;
				cf[a[i]+1]-=a[i]-a[i-1]-1;
			}
		} 
		else{//a[i-1]>a[i]
			res+=m-a[i-1]+a[i];
			if(m-a[i-1]+a[i]>=2){
				if(a[i-1]+2>m){
					int s=a[i-1]+2-m;
					ccf[s]++;
					ccf[a[i]+1]--;
					cf[a[i]+1]-=a[i]-s+1;
				}
				else{
					ccf[a[i-1]+2]++;
					cf[1]+=m-a[i-1];
					ccf[a[i]+1]--;
					ccf[2]++;
					cf[a[i]+1]-=m-a[i-1]+a[i]-1;
				}
			}
		}
	} 
	LL maxi=0;
	rb(i,1,m)
		ccf[i]+=ccf[i-1],cf[i]+=ccf[i],cf[i]+=cf[i-1],maxi=max(maxi,cf[i]);
//	cout<<maxi<<endl;
	cout<<res-maxi<<endl;
	return 0;
}
/*

2 4
1 3

*/