#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

int main(void)
{
    string a, b, c;
    cin >> a >> b >> c;

    deque<char> A(a.begin(), a.end());
    deque<char> B(b.begin(), b.end());
    deque<char> C(c.begin(), c.end());

    char target = A.front();
    A.pop_front();
    string ans;
    while (true)
    {
        if (target == 'a')
        {
            if (A.empty())
            {
                ans = "A";
                break;
            }
            target = A.front();
            A.pop_front();
        }
        else if (target == 'b')
        {
            if (B.empty())
            {
                ans = "B";
                break;
            }
            target = B.front();
            B.pop_front();
        }
        else
        {
            if (C.empty())
            {
                ans = "C";
                break;
            }
            target = C.front();
            C.pop_front();
        }
    }
    cout << ans << endl;
    return (0);
}