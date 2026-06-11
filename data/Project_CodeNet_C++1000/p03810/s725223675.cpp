//in the name of <Allah>
#include <bits/stdc++.h>
using namespace std;

const int N = 1 * 100 * 1000 + 1;
int n, a[N];
string ans[] = {"Second", "First"};

bool chek() {
    int cnt[] = {0, 0}, x = 0;
    for (int i = 0; i < n; i++)
        cnt[a[i] & 1]++, x += (a[i] == 1); 
    if (cnt[0] & 1)
        return true;
    if (cnt[1] > 1)
        return false;
    if (x) 
        return false;
    int g = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] & 1)
            a[i]--;
        g = __gcd(g, a[i]);
    }   
    for (int i = 0; i < n; i++)
        a[i] /= g;
    return (!chek());
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << ans[(n - 1 && chek())] << endl;
}
