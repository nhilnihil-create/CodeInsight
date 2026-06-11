#include <bits/stdc++.h>
#define fr(i, n, m) for(int i = (n); i < (m); i ++)
#define pb push_back
#define y first
#define x second

using namespace std;
typedef unsigned long long ll;

int main()
{
    int n, t;
    cin >> n >> t;
    int a[n];
    fr(i, 0, n){
        cin >> a[i];
    }
    int mi = a[0];
    int c = 0;

    int di = -1e9;

    fr(i, 1, n){
        if(a[i] > mi){
            if(a[i] - mi > di){
                c = 1;
                di = a[i] - mi;
            }
            else if(a[i] - mi == di){
                c ++;
            }
        }
        else{
            mi = a[i];
        }
    }
    cout << c << endl;
    return 0;
}
