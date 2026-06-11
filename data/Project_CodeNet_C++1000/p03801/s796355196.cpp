#include<bits/stdc++.h>
using namespace std;

int main(void) {
    long n;
    cin >> n;

    vector<pair<long,long>> a(n);
    for(long i=0; i<n; i++)
        cin >> a[i].first, a[i].second = -i;

    sort(a.begin(), a.end(), greater<>());

    map<long, long> res;

    long top, cur;
    tie(top, cur) = a[0];
    cur = -cur;
    for(long i=1; i<n; i++) {
        res[cur] += i*(top - a[i].first);
        top = a[i].first;
        cur = min(cur, -a[i].second);
    }
    res[cur] += n*top;

    for(long i=0; i<n; i++)
        cout << res[i] << endl;
}
