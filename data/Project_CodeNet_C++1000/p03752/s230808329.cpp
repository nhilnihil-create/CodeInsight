// https://atcoder.jp/contests/s8pc-4/tasks/s8pc_4_b

#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;


int main(int argc, const char* argv[])
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    uint64_t minCost = numeric_limits<uint64_t>::max();
    for(int i = 0; i < (1 << n); ++i)
    {
        if(bitset<32>(i).count() < k)
        {
            continue;
        }
        uint64_t cost = 0;
        int maxHeight = 0;
        for(int j = 0; j < n; ++j)
        {
            if(((i >> j) & 1) == 1)
            {
                if(maxHeight < a[j])
                {
                    maxHeight = a[j];
                }
                else
                {
                    cost += maxHeight - a[j] + 1;
                    maxHeight++;
                }
            }
            else
            {
                maxHeight = max(maxHeight, a[j]);
            }
            
        }
        minCost = min(minCost, cost);
    }

    cout << minCost << endl;
}
