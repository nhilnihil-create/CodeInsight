#include<iostream>
#include<math.h>
void solve();
typedef long long ll;
using namespace std;
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int cases;
    cases = 1;
    for (int i = 0 ; i < cases; i++) {
        solve();
        cout << '\n';
    }
    return 0;
}

void solve() {
    int n;
    cin >> n;
    int a[n];
    int count = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        //Skip parts where no change
        while (i + 1 < n && a[i] == a[i + 1]) i++; 
        //Skip decreasing parts
        if (i + 1 < n && a[i] > a[i + 1]) while(i + 1 < n && a[i] >= a[i + 1]) i++;
        //Skip increasing parts
        else if (i + 1 < n && a[i] < a[i +1]) while (i + 1 < n && a[i] <= a[i + 1]) i++;
        count++;
    }
    cout << count;
}