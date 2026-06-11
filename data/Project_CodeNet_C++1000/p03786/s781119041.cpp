#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef pair<int , int> ii;
typedef pair<ii , int> iii;
ll n , x[200000] , prefix[200000] , ans;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> x[i];
	}
	sort(x + 1 , x + n + 1);
	for(int i = 1 ; i <= n ; i++){
		prefix[i] = prefix[i - 1] + x[i];
	}
	x[n + 1] = 0;
	for(int i = n ; i >= 1 ; i--){
		if(2*prefix[i] >= x[i + 1])ans++;
		else break;
	}
	cout << ans << endl;
}