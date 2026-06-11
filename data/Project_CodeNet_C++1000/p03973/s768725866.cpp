#include <iostream>
using namespace std;

const int N = 100 * 1000 + 10;

int n;
long long ans;
int arr[N];

void input() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    return;
}

void solve() {
    int rate = 2;
    for (int i = 1; i < n; i++)
        if (arr[i] == rate)
            rate++;
        else
            ans += (arr[i] - 1) / rate;
    return;
}

int main() {
    input() ;
    solve() ;
    cout << ans + arr[0] - 1 << endl;
    return 0;
}
