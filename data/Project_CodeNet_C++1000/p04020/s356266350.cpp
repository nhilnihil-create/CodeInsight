#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 100;
long long arr[N];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin >> n;
    long long s = 0;
    for(int i = 1;i <= n;++i)cin >> arr[i];
    long long ans = 0;
    for(int i = 1;i <= n;i++){
        ans += (arr[i] / 2);
        arr[i] %= 2;
        long long t = min(arr[i], arr[i + 1]);
        arr[i] -= t;
        arr[i + 1] -= t;
        ans += t;
    }
    cout << ans;
	return 0;
} 