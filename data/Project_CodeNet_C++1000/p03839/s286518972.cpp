#include <iostream>
using namespace std;

int main() {
    int n, k;
    long long ans = 0, b[100001], s[100001];
    cin >> n >> k;
    b[0] = s[0] = 0;
    for(int i=1;i<=n;i++){
        long long a;
        cin >> a;
        b[i] = b[i-1];
        if(a>0)b[i] += a;
        s[i] = s[i-1] + a;
    }
    for(int i=k;i<=n;i++){
        long long r = b[n] - b[i] + b[i-k];
        r += max((long long)0, s[i] - s[i-k]);
        ans = max(ans, r);
    }
    cout << ans << endl;
    
	return 0;
}