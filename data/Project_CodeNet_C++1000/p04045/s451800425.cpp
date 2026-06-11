#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int a[10];
bool f(int n) {
    while(n > 0) {
        if(a[n % 10])
            return true;
        n /= 10;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    while(k--) {
        int e;
        cin >> e;
        a[e] = 1;
    }

    while(f(n)) n++;
    cout << n << '\n';
    return 0;
}

