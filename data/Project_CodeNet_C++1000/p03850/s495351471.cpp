#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> P;
 
#define pb push_back
#define fr first
#define sc second

int main(){
	int N;
	scanf("%d",&N);
	ll sum;
	scanf("%lld",&sum);
	
	static int cnt = 0;
	static vector<ll> vec[100010];
	for(int i = 2 ; i <= N ; i ++){
		char c;
		ll x;
		scanf(" %c %lld",&c,&x);
		sum += x;
		if(c == '-')cnt ++;
		vec[cnt].pb(x);
	}
	if(cnt == 0){
		cout << sum << endl;
		return 0;
	}
	ll ret = 1000000000000000000;
	ll S = 0;
	for(int i = 1 ; i <= cnt+1 ; i ++){
		if(vec[i].size() == 0){
			ret = min( ret , S );
			break;
		}
		ll T = S;
		for(int j = 0 ; j < vec[i].size() ; j ++){
			T += vec[i][j];
		}
		ret = min( ret , T );
		S += vec[i][0];
	}
	cout << sum-ret*2 << endl;
}
