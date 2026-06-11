#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;


int n, d, cnt[N], was[N];
void no(){
	cout << "Impossible";
	exit(0);
}
int main()
{                         
	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		cnt[x]++;
		d = max(d, x);
	}
	for(int i = 0; i <= d; i++){
		int x = max(i, d - i);
		if(cnt[x] == 0)
			no();
		cnt[x]--;
		if(i != 0 && i != d)
			was[x + 1] = 1;
	}
	for(int i = 0; i < N; i++)
		if(cnt[i] && !was[i])
			no();	
	cout << "Possible";
	return 0;
}
