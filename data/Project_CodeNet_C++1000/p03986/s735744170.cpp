#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    string X;
    cin >> X;

    ll n = X.size();
    stack<char> stackX;
    REP(i, n)
    {
        if (!stackX.empty())
        {
            if (X[i] == 'S')
            {
                stackX.push(X[i]);
            }
            else if (X[i] == 'T')
            {
                if (stackX.top() == 'S')
                {
                    stackX.pop();
                }
                else
                {
                    stackX.push(X[i]);
                }   
            }
        }
        else
        {
            stackX.push(X[i]);
        }
    }
    ll ans = stackX.size();

    cout << ans << endl;
}
