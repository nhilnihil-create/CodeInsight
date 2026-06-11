#include <bits/stdc++.h>

#define ln "\n"
#define SORT(X) sort(X.begin(), X.end())
#define SORTi(X) sort(X.begin(), X.end(), greater<ll>())
#define REP(x, a, b) for (auto x = a; x <= b; x++)
#define REPi(x, b, a) for (auto x = b; x >= a; x--)
#define REPit(x, A) for (auto x = A.begin(); x != A.end(); x++)
#define REPr(x, A) for (auto x : A)
#define ll long long
#define ull unsigned long long
#define PB push_back
#define EB emplace_back
#define UMP unordered_map
#define UST unordered_set

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string A, B, C;
    cin>>A>>B>>C;
    if(A[A.size()-1] == B[0] && B[B.size()-1] == C[0])
        cout<<"YES"<<ln;
    else
        cout<<"NO"<<ln;
    return 0;
}