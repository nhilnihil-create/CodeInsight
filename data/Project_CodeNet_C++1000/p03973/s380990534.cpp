#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <climits>
#include<cmath>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define INF INT_MAX/3
#define REP(i,n) for(int i=0;i<n;i++)
#define show(x) cout<< #x << " = " << (x) << endl
#define show_array(arr) REP(i,int((arr).size()))cout<< #arr << "["<<i<<"]"<<"="<<arr[i]<<endl


int main(){
	
	ios::sync_with_stdio(false);
	ll N;
	cin>>N;
	vector<ll> arr(N);
	REP(i,N)cin>>arr[i];
	ll sell_count = 0;	
	sell_count = arr[0] - 1;
	ll P = 2;	
	for(ll i = 1; i < N; i++ ){
		
		if(arr[i] == P){
			P++;
			continue;
		}
	
		ll s_c;
		if(arr[i] % P == 0 ){
			s_c = arr[i] / P - 1;
		}else{
			s_c = arr[i] / P;
		}
		sell_count += s_c;
	}

	cout<<sell_count<<endl;
	
	return 0;
}
