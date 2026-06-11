#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int AMAX = 100000;
long long int cnt[AMAX + 1];

int main()
{
    int N;
    long long K;
    
    cin >> N >> K;

    for(int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        cnt[a] += b;
    }

    for(int i = 1; i <= 100000; i++)
    {
        if ( K <= cnt[i])
        {
            cout << i << endl;
            break;
        }
        K -= cnt[i];
    }
    
    return 0;
}