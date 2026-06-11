#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <bitset>
using namespace std;

long long pow(int a, int b)
{
    long long ans = 1;
    for (int i = 0; i < b; i++)
    {
        ans *= a;
    }
    
    return ans;
}

int main(void)
{
    int N, P;
    cin >> N >> P;

    // event ... true
    // odd ... false
    vector<int> a(N, 0);

    int even_count = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        if(a[i] % 2 == 0) even_count++;
    }

    long long ans;
    // all even number
    if (even_count == N)
    {
        if (P == 0)
        {
            ans = pow(2, N);
        }
        else
        {
            ans = 0;
        }
        
    }
    else
    {
        ans = pow(2, N - 1);
    }
    

    cout << ans << endl;
}