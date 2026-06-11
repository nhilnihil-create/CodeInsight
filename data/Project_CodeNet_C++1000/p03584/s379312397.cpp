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
const int MAX=1e5+10;

int main(){
	int N, K;
	cin>>N>>K;
	int A[MAX], B[MAX];
	rep(i,N)cin>>A[i]>>B[i];
	
	int l=0;
	rep(i,30)if((K>>i) & 1)l=i+1;
	
	ll ans=0;
	rep(a,N){
		if((A[a] | K )== K)ans=ans+(ll)B[a];
	}
	rep(d,l)if((K>>d) & 1){
		ll tmp=0;
		int P=0;
		rep(i,l){
			if(i<d)P = P | (1<<i);
			else if(i>d) P = P | (K & (1<<i));
		}
		rep(a,N){
			if((A[a] | P) == P)tmp=tmp+(ll)B[a];
		}
		ans=max(ans, tmp);
	}
	cout<<ans<<endl;
}