#include <iostream>
#include <iomanip>
#include <ios> 
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <bitset>
#include <map>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define sz(c) ((int)(c).size())

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
//typedef pair<int, int> P;
//typedef pair<int, pair<int, int> > PP;
const int MAX=1e5+10;

int main(){
	int N;
	cin>>N;
	int a[MAX];
	rep(i,N){
		cin>>a[i];
	}
	sort(a, a+N);
	
	bool ans;
	if(a[N-1]-a[0]==0){
		int k=a[0];
		if(k<=N/2 || k==N-1)ans=true;
		else ans=false;
	}
	else if(a[N-1]-a[0]==1){
		int k=a[0];
		int al=0;
		rep(i,N)if(a[i]==k)al++;
		int rm=N-al;
		if(rm>=2 && al+1<=k+1 && k+1<=al+rm/2)ans=true;
		else ans=false;
		
	}
	else ans=false;
	
	if(ans)cout<<"Yes";
	else cout<<"No";
}