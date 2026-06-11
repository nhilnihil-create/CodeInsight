#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, C, K;
    cin >> N >> C >> K;
    vector<int> T(N);
     for (int i = 0; i < N; ++i)
    {
        cin >> T[i];
    }
    sort(T.begin(), T.end());
    int ans = 1;
    int earliest = T[0];
    int count = 1;
     for (int i = 1; i < N; ++i)
    {
        if(T[i] - earliest > K || count >= C){
            earliest = T[i];
            count = 1;
            ++ans;
            continue;
        }
        ++count;
    }
    cout << ans << endl;
}