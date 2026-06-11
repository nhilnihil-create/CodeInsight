#include <iostream>
#include <iomanip>
#include <list>
typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)

int main()
{
    int n;
    cin >> n;
    list<int> ans;
    repi(i, n, 0)
    {
        int a;
        cin >> a;
        if (n % 2)
        {
            if (i % 2)
            {
                ans.push_back(a);
            }
            else
            {
                ans.push_front(a);
            }
        }
        else
        {
            if (i % 2)
            {
                ans.push_front(a);
            }
            else
            {
                ans.push_back(a);
            }
        }
    }
    for (auto itr = ans.begin(); itr != ans.end(); itr++)
        cout << *itr << " ";
    cout << endl;
    return 0;
}