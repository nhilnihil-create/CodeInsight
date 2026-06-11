#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9;
using namespace std;
using ll = long long;
vector <int> x(10000);
int main() {
    int x , a , b;
    cin >> x >> a >> b;
    if(abs(x - a) > abs(x - b)){
        cout << 'B' << endl;
    }
    if(abs(x - a) < abs(x - b)){
        cout << 'A' << endl;
    }
}