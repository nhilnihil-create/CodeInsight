#include <bits/stdc++.h>
#define ss second
#define ff first
#define all(x) x.begin(), x.end()
 
// #define DEBUG 100
 
using namespace std;
using ll = unsigned long long;
using pii = pair<int, int>;
 
const int oo = 1e9 + 7;
const ll mod = 1e9 + 7,maxn = 100010;
const double PI = acos(-1);
 
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0); 
    int x, y, a[] = {1, 3, 5 ,7 ,8, 10, 12};
    cin >> x >> y;
 
    int cnt = 0;
 
    for (int i=0; i<7; i++){
        if (x == a[i] || y == a[i]) cnt++;
    }
    if (cnt == 2) {
        cout << "Yes" << endl;
        return 0;
    }
    if (cnt == 1 || x == 2 || y == 2) {
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
    }
    return 0;
}