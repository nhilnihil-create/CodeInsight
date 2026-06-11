#include <bits/stdc++.h>
#define ll uint64_t
#define vi vector <int>
#define vl vector <ll>
#define dl pair <ll, ll>
#define ii pair <double, double>
#define vii vector <ii>
#define graph vector <set <int> >
#define REP(a, b, step) for (int i = a; i < b; i += step)
#define inf 100000000

using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
 
    int n, k;
    cin >> n >> k;
    bool arr[10] = {1,1,1,1,1,1,1,1,1,1};
    int in;
    REP(0, k, 1) {
    	cin >> in;
    	arr[in] = 0;
    }
    REP(n, 10000000, 1) {
    	int div = 1;
    	while (div <= i) {
    		if (!arr[(i / div) % 10]) break;
    		div *= 10;
    	}
    	if (div > i) {
    		cout << i << "\n";
    		break;
    	}
    }
    return 0;
}