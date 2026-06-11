#include <bits/stdc++.h>
#define ll uint64_t
#define vi vector <int>
#define vl vector <ll>
#define dl pair <ll, ll>
#define ii pair <ll, ll>
#define vii vector <ii>
#define graph vector <set <int> >
#define REP(a, b, step) for (int a = 0; a < b; a += step)
#define inf 1000000000
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
 
    int n, l;
    cin >> n >> l;
    string arr[n];
    REP(i, n, 1) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    REP(i, n, 1) {
        cout << arr[i];
    }
    cout << "\n";
    return 0;
}