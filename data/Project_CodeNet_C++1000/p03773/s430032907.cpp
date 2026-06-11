#include <iostream>
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
#include <cmath>

#pragma GCC optimize("O3")

using namespace std;
typedef long long ll;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b;
    cin >> a >> b;
    cout << (a + b) % 24;
}