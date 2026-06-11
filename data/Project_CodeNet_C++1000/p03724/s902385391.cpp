#include<bits/stdc++.h>

using namespace std;

int main(void) {
    long n, m;
    cin >> n >> m;

    map<long,long> p;
    for(long i=0; i<m; i++) {
        long a, b;
        cin >> a >> b;
        p[a]++, p[b]++;
    }

    cout << (all_of(p.begin(), p.end(), [&](auto t){return ~t.second&1;}) ? "YES" : "NO") << endl;
}
