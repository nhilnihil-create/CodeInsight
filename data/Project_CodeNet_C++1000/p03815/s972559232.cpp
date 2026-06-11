#include "bits/stdc++.h"

using namespace std;

int main() {
    long long n;
    cin >> n;
    if(n <= 6)cout << 1;
    else if(n <= 11)cout << 2;
    else{
        if(n % 11 == 0)cout << n / 11 * 2;
        else if(n % 11 <= 6)cout << n / 11 * 2 + 1;
        else cout << n / 11 * 2 + 2;
    }

	return 0;

}
