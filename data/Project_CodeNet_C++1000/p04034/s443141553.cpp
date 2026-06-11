#include <iostream>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <cmath>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);
#pragma GCC optimize("O3")

using namespace std;
typedef long long ll;

int freq[100005];

int main()
{
    FAST;
    int n, m;
    cin >> n >> m;
    unordered_set<int> us;
    us.insert(1);
    int a1, a2;
    memset(freq,  0, sizeof(freq));
    for (int i = 0; i < m; i++)
    {
        cin >> a1 >> a2;
        freq[a1]--;
        freq[a2]++;
        // cout << freq[a1] << " " << freq[a2] << "\n";
        if (us.count(a1))
        {
            us.insert(a2);
            if(freq[a1] == -1)
                us.erase(a1);
        }
    }
    cout << us.size();
}