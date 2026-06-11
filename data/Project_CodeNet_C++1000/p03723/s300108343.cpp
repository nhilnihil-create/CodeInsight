#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define ll long long
#define mod 100000007
#define rep(i, n) for (int i = 0; i < n; ++i)
using Graph = vector<vector<int>>;


int lcm(ll a, ll b)
{
    return a * b / __gcd(a, b);
}

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main()
{
    int A,B,C;
    cin >> A >> B >> C;
    ll ans = 0;
    ll tmpA, tmpB, tmpC;
    if(A%2 == 1|| B%2 == 1||C%2 == 1){
        cout << ans << endl;
    }
    else if(A == B && B== C){
        cout << -1 << endl;
    }
    else
    {
        while(A%2 == 0 && B%2 == 0 && C%2 == 0){
            tmpA = B / 2 + C / 2;
            tmpC = A / 2 + B / 2;
            tmpB = C / 2 + A / 2;
            A = tmpA;
            B = tmpB;
            C = tmpC;
            ans++;
        }
        cout << ans << endl;

    }
}
