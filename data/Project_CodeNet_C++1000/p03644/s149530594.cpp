#include<bits/stdc++.h>
#define rep(i, n) for (int i=0; i < n; i++)
#define repd(i, n) for (int i = n-1; i > -1; i--)
typedef long long ll;
using namespace std;

int main()
{
    int n; cin >> n;
    repd(i, 7){
        if (1<<i <= n) {
            cout << (1<<i) << endl;
            break;
        }
    }
}