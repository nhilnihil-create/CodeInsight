#include<bits/stdc++.h>
using namespace std;

int main(void) {
    long n;
    cin >> n;
    vector<long> a(n);
    for(auto &e: a) cin >> e;

    if(n==1) {
        cout << "YES" << endl;
        return 0;
    }

    long sum = 0;
    for(auto &e: a) sum += e;
    long cnt = sum / (n * (n+1) /2);

    if(cnt * (n*(n+1)/2) != sum) {
        cout << "NO" << endl;
        return 0;
    }

    vector<long> k(n);
    {
        long t = 0;
        for(long i=0; i<n; i++) {
            // a[i+1] - a[i] == x - (n-1)*(cnt-x)
            // a[i+1] - a[i] == x - (n-1)*cnt + (n-1)x
            // nx == a[i+1] - a[i] + (n-1)*cnt
            long nx = a[(i+1)%n] - a[i] + (n-1)*cnt;
            long x = nx / n;
            if (x*n != nx) {
                cout << "NO" << endl;
                return 0;
            }
            if(!(0 <= x && x <= cnt)) {
                cout << "NO" << endl;
                return 0;
            }
            k[i] = x;
            t += cnt - x;
        }

        if(t != cnt) {
            cout << "NO" << endl;
            return 0;
        }
    }

    long s = cnt - k[n-1];
    for(long i=1; i<n; i++)
        s += (n+1-i)*(cnt - k[i-1]);

    a[0] -= s;
    for(long i=1; i<n; i++) {
        s += cnt;
        s -= n * (cnt - k[i-1]);
        a[i] -= s;
    }
    for(auto &e: a) {
        if(e) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}
