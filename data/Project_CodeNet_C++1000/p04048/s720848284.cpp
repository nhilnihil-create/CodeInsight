#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1000300;
const long long mod = 1e9 + 7;

using namespace std;

long long f(long long a, long long b)
{
        if(!a || a == b){
                return a;
        } else if(a > b){
                return f(b, a);
        } else{
                return ((b - 1) / a) * 2 * a + f(b - (b - 1) / a * a, a);
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        long long n, x;
        cin >> n >> x;
        cout << f(n - x, x) + n << "\n";
}
