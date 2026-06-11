#include <bits/stdc++.h>
using namespace std;
mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());

template<typename T>
void debug(T var, string label){
    cout << label << " " << var << '\n';
}

typedef long long ll;

void solve(){
    int n;
	cin >> n;
	   pair<int,int> a[n];
	for(int i = 0; i < n; ++i){
		cin >> a[i].first >> a[i].second;
	}
	sort(a, a + n);
	int ans = a[n - 1].second + a[n - 1].first;
	cout << ans << '\n';
}
int main()
{

    //freopen("C:/Users/LIB-606/Desktop/Contest/in.txt", "r", stdin);
    // freopen("C:/Users/LIB-606/Desktop/Contest/out.txt", "w", stdout);

    for(int i = 0; i < 1; ++i)
	    solve();
}
