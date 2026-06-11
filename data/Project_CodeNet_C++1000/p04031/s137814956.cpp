#include <bits/stdc++.h>
#define s second
#define f first
#define pb push_back
#define endl '\n'
using namespace std;


typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	vector<int> V(T);

	ll sum = 0;

	for(int qq = 0; qq < T; qq++){
		cin >> V[qq];
		sum += V[qq];
	}

	ll sum2 = sum;

	sum = ceil((double)sum/T);

	ll ans = 0;

	sort(V.begin(), V.end());

	for(int i = 0; i < T; i++){
		ans += (V[i] - sum)*(V[i] - sum);
	}

	ll ans2 = 0;
	
	sum2 /= T;

	for(int i = 0; i < T; i++){
		ans2 += (V[i] - sum2)*(V[i] - sum2);
	}

	cout << min(ans,ans2) << endl;

	

	return 0;
}
