// Words are flowing out like endless rain into a paper cup
// They slither while they pass they slip away across the universe
// Pools of sorrow, waves of joy are drifting through my open mind
// Possessing and caressing me

#include <bits/stdc++.h>
using namespace std;

using LL = long long;

namespace _buff {

const size_t BUFF = 1 << 21;
char ibuf[BUFF], *ib = ibuf, *ie = ibuf;
char getc() {
    if (ib == ie) {
        ib = ibuf;
        ie = ibuf + fread(ibuf, 1, BUFF, stdin);
    }
    return ib == ie ? -1 : *ib++;
}

}

LL read() {
    using namespace _buff;
    LL ret = 0;
    bool pos = true;
    char c = getc();
    for (; (c < '0' || c > '9') && c != '-'; c = getc()) {
        /* assert(~c); */
    }
    if (c == '-') {
        pos = false;
        c = getc();
    }
    for (; c >= '0' && c <= '9'; c = getc()) {
        ret = (ret << 3) + (ret << 1) + (c ^ 48);
    }
    return pos ? ret : -ret;
}

int main() {
    int n = read();
    vector<int> a(n);
    generate_n(begin(a), n, read);
    sort(begin(a), end(a), greater<int>());

    int p = 0;
    for (; p < n; ++p) {
        if (p >= a[p]) {
            break;
        }
    }
    --p;
    int q = 0;
    for (; q < n; ++q) {
        if (a[q] <= p) break;
    }

    puts(~(a[p] - p) & 1 || ~(q - p) & 1 ? "First" : "Second");

    return 0;
}
