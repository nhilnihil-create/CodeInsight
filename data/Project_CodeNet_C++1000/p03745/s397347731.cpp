#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int res = 1;
    int d;
    if(a[0] > a[1]) d = 1;
    else if(a[0] < a[1]) d = -1;
    else d = 0;
    for (int i = 1; i < n; i++)
    {
        if(d == 0) {
            if(a[i-1] > a[i]) d = 1;
            else if(a[i-1] < a[i]) d = -1;
            else d = 0;
        }
        else {
            if(d < 0 && a[i-1] > a[i]) {
                res++;
                i++;
                if(a[i-1] > a[i]) d = 1;
                else if(a[i-1] < a[i]) d = -1;
                else d = 0;
            }
            else if(d > 0 && a[i-1] < a[i]) {
                res++;
                i++;
                if(a[i-1] > a[i]) d = 1;
                else if(a[i-1] < a[i]) d = -1;
                else d = 0;
            }
        }
    }

    cout << res << endl;
    return 0;
}
