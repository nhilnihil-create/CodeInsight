#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll N;
    cin >> N;

    ll count = 0;
    count = N / 11 * 2;
    N %= 11;
    if(N == 0)
    {
        
    }
    else if(N <= 6)count++;
    else count += 2;
    
    cout << count << endl;
    return 0;
}