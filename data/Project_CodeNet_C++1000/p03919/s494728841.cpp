#include <bits/stdc++.h>
#define int long long
#define f(i,n) for(int i=0;i<n;i++)
#define INF INT_MAX
#define LINF LLONG_MAX
#define mod 1000000007
#define pie 3.141592653589793238462643383279
#define P pair<int,int>
#define prique priority_queue
#define F first
#define S second
using namespace std;
signed main(){
	int a,b;
	cin>>a>>b;
	f(i,a){
		f(j,b){
			string s;
			cin>>s;
			if(s=="snuke"){
				cout<<(char)('A'+j)<<i+1<<endl;
				return 0;
			}
		}
	}
	return 0;
}

