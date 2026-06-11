#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    if(N / 10 == 9 || N % 10 == 9) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}