#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    int dist[n];
    int sum =0;
    int i;
    for(i=0; i<n; i++){
        cin >> a[i];
        if(abs(a[i] - k) > abs(a[i])){
            dist[i] = abs(a[i]);
        } else {
            dist[i] = abs(a[i] - k);
        }

        sum += dist[i];
    }

    cout << sum * 2 << endl;
}

