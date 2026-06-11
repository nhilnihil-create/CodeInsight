#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, c, k;
    long long t[100010];
    cin >> n >> c >> k;
    for (long long i=0; i<n; i++) {
        cin >> t[i];
    }
    sort(t, t+n);
    long long bn = 0;
    for (long long i=0; i<n;){
        long long temp = 0;
        for (int j=1; j<=c;){
            if (j == c){
                temp += j;
                bn++;
                break;
            }
            else if (t[i+j]<=t[i]+k){
                j++;
            }
            else if (t[i+j]>t[i]+k){
                temp += j;
                bn++;
                break;
            }
        }
        i += temp;
        if (i>=n) break;
    }
    cout << bn << endl;
    return 0;
}