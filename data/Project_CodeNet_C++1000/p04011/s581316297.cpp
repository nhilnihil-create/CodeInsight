#include<iostream>
#include<string>
#include <vector>
#include <algorithm>
#include <deque>
#include<sstream>

using namespace std;
typedef long long int lli;

const int INF = 100100100;

int main()
{
    int n, k, x, y;

    cin >> n >> k >> x >> y;

    int a = (n < k) ? n : k;
    int b = (n < k) ? 0 : n - k;


    cout << x * a + y * b << endl;
    return 0;
}