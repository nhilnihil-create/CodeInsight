#include <bits/stdc++.h>
using namespace std;
int main() {
    int N; cin >> N;
    long long a[N];
    for(int i = 0; i < N; i++) cin >> a[i];
    long long po = 0, pe = 0;
    long long sum = 0;
    for (int i = 0; i < N; i++)
    {
        if(i % 2 == 1 && sum + a[i] >= 0) {
            po += abs(- sum - 1 - a[i]);
            sum = -1;
        }
        else if(i % 2 == 0 && sum + a[i] <= 0) {
            po += abs(- sum - a[i] + 1);
            sum = 1;
        }
        else sum += a[i];
    }
    sum = 0;
    for (int i = 0; i < N; i++)
    {
        if(i % 2 == 1 && sum + a[i] <= 0) {
            pe += abs(- sum - a[i] + 1);
            sum = 1;
        }
        else if(i % 2 == 0 && sum + a[i] >= 0) {
            pe += abs(- sum - 1 - a[i]);
            sum = -1;
        }
        else sum += a[i];
    }

    cout << min(po, pe) << endl;
    return 0;
}