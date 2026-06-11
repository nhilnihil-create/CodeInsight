#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <cmath>

using namespace std;

int main()
{
    int n,t;
    cin >> n >> t;
    int ends = 0;
    int x;
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        cin >> x;
        ans += (x<ends ? x+t-ends : t);
        ends = x+t;
    }
    cout << ans <<endl;
}
