#include <bits/stdc++.h>
using namespace std;

long min(long a, long b, long c) {
    if(a < b) {
        if(a < c) {
            return a;
        } else {
            return c;
        }
    } else {
        if(b < c) {
            return b;
        } else {
            return c;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<long> a(n);
    long sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a.at(i);
        sum += a.at(i);
    }
    long ave1 = sum / n;
    long ave2 = ave1 - 1;
    long ave3 = ave1 + 1;
    
    long res1 = 0;
    long res2 = 0;
    long res3 = 0;
    
    for(int i = 0; i < n; i++) {
        res1 += pow((a.at(i) - ave1), 2);
        res2 += pow((a.at(i) - ave2), 2);
        res3 += pow((a.at(i) - ave3), 2);
    }
    long res = min(res1, res2, res3);
    
    cout << res << endl;
}