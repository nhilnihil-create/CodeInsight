#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, K;
    cin >> N >> K;
    int ans = 0;
    for (int i=0; i<N; i++){
    	int x, a, b;
    	cin >> x;
        a=x;
      	b=K-x;
		if (a<0) a = -a;
        if (b<0) b = -b;
        if (a<=b) ans += 2*a;
        if (a>b) ans += 2*b;
    }
    cout << ans << endl;
}