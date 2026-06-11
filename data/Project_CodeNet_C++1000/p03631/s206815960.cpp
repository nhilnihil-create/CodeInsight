#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

typedef pair<ll, pair<int, int> > p;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    string N;
    cin >> N;

    if(N[0] == N[2]) cout << "Yes" << endl;
    else cout << "No" << endl;
}