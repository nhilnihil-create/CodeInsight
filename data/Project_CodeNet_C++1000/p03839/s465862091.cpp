#include <iostream>

using namespace std;

const int MAXN = 1e5 + 5;

int n,k;
int niz[MAXN];
long long pref[MAXN];
long long ppref[MAXN];

int main () {
    cin >> n >> k;
    for (int i = 0 ; i < n; i ++) {
        cin >> niz[i];
    }
    pref[0] = niz[0];
    if (niz[0] > 0) {ppref[0] = niz[0];}
    else {ppref[0] = 0;}
    for (int i = 1 ; i < n ; i++) {
        pref[i] = niz[i] + pref[i-1];
        ppref[i] += ppref[i-1];
        if (niz[i] > 0) {ppref[i] += niz[i];}
    }
    long long sol = 0;
    //cout <<"PREFIKS SUME: " << endl;
    /*for (int i = 0 ; i < n ; i++) {
        cout << pref[i] <<" ";
    }
    cout << endl << "POZITIVAN PREF: " << endl;
    for (int i = 0 ; i < n ; i++) {
        cout << ppref[i] << " ";
    }*/
    //cout << endl;
    long long z = pref[k-1] + ppref[n-1] - ppref[k-1];
    long long z1 = ppref[n-1] - ppref[k-1];
    if (z > sol) sol = z;
    if (z1 > sol) sol = z1;
    for (int i = 1 ; i < n-k+1 ; i++) {
        long long u, u1;
        if (i < n-k) u = ppref[i-1] + pref[i+k-1] - pref[i-1] + ppref[n-1] - ppref[i+k-1];
        if (i < n-k) u1 = ppref[i-1] + ppref[n-1] - ppref[i+k-1];
        if (i == n-k) {
            u = ppref[i-1] + pref[n-1] - pref[i-1];
            u1 = ppref[i-1];
        }
        if (u > sol) sol = u;
        if (u1 > sol) sol = u1;
    }
    cout << sol;
    return 0;
}
