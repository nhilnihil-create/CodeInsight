#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int x[100002], b[100002]{0};
    for(int i = 0; i < n; i++){
        cin >> x[i];
        b[x[i]]++;
    }
    int s[100002]{0}, r[100002]{0};
    for(int i = 1; i <= 100000; i++){
        s[i % m] += b[i];
        r[i % m] += b[i] / 2;
    }
    int ans = s[0] / 2;
    for(int i = 1; i <= (m - 1) / 2; i++){
        if(s[i] > s[m - i]) ans += s[m - i] + min(r[i], (s[i] - s[m - i]) / 2);
        else ans += s[i] + min(r[m - i], (s[m - i] - s[i]) / 2);
    }
    if(m % 2 == 0) ans += s[m / 2] / 2;
    cout << ans << endl;
}