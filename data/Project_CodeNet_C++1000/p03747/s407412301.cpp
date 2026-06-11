#include <bits/stdc++.h>
using namespace std;

const int DIM = 1e5 + 5;

int arr[DIM];

int main(void)
{
    int n, l, t;
    cin >> n >> l >> t;
    
    long long pos = 0;
    for (int i = 0; i < n; ++i) {
        int p, d;
        cin >> p >> d;
        
        if (d == 1) p += t;
        else        p -= t;
        
        pos += p / l; p %= l;
        if (p < 0) pos--, p += l;
        
        arr[i] = p;
    }
    
    sort(arr, arr + n);
    for (int i = 0; i < n; ++i)
        cout << arr[(pos % n + n + i) % n] << "\n";
    
    return 0;
}

