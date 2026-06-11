#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int n,m,c=0,d=0,ans=1;
    cin >> n;

    for (int i = 1; i < n+1; i++)
    {
        m = i;
        while (m%2==0)
        {
            m=m/2;
            c++;
        }
        if(c>d){
            d = c;
            ans = i;
        }
        c = 0;
    }
    cout << ans << endl;
    return 0;
}