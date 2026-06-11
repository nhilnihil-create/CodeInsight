#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> p;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<bool> x(pow(10, 5));

    int c = 0;

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        a--;
        if(x[a]) c++;
        else x[a] = true;
    }

    if(c % 2) c++;

    cout << N - c << endl;
}