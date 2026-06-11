#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

int n, panjang, dp[5005][5005];
long long hasil;
string s;

int hitung(int pos, int sisa) {
    if (sisa == 0) {
        if (pos == panjang)
            return 1;
        return 0;
    }
    int &ret = dp[pos][sisa];
    if (ret != -1)
        return ret;
    ret = (2 * hitung(pos + 1, sisa - 1)) % mod;
    if (pos > 0)
        ret = (ret + hitung(pos - 1, sisa - 1)) % mod;
    else
        ret = (ret + hitung(pos, sisa - 1)) % mod;
    return ret;
}
long long pangkat(int base, int ekspo) {
    if (ekspo == 0)
        return 1;
    if (ekspo == 1)
        return base % mod;
    long long temp = pangkat(base, ekspo / 2);
    temp = (temp * temp) % mod;
    if (ekspo % 2 == 1)
        temp = (temp * base) % mod;
    return temp;
}

int main() {
    memset(dp, -1, sizeof dp);
    scanf("%d", &n);
    cin >> s;
    panjang = s.length();
    hasil = hitung(0, n);
    hasil = (hasil * pangkat(pangkat(2, panjang), mod - 2)) % mod;
    printf("%d\n", hasil);
    return 0;
}