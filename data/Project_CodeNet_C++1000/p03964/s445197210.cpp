#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	ll lastT = 1, lastA = 1;
	for (int i = 0; i < n; i++) {
		ll t, a;
		cin >> t >> a;

		ll factor=max(lastA/a,lastT/t);
        while(true){
            if(factor * t >= lastT && factor * a >= lastA)
                break;
            factor++;
        }

		lastT = t * factor;
		lastA = a * factor;
	}

	//cout << "ans: " << lastT << " " << lastA << '\n';
	cout << (lastT + lastA) << endl;
    return 0;
}