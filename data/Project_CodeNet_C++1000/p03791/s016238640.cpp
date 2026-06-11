#include<bits/stdc++.h>
using namespace std;


typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

#define pb push_back
#define mp make_pair
#define snd second
#define fst first
#define debug printf("--%d--\n",__LINE__)
#define ll long long int
#define MODP 1000000007;

int N;
ll x[114514];
int main(void){
	cin >> N;
	for(int i=0;i<N;i++) cin >> x[i];
	ll ans = 1;
	ll cnt = 0;
	for(int i=0;i<N;i++){
		if (i>0){
			cnt = max(cnt, i - (x[i-1]+1)/2);
		}
		ans = (ans * (i+1-cnt)) % MODP;
	}
	cout << ans << endl;
	
	
	
	return 0;
}
