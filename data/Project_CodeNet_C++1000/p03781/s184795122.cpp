#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#define INF 1000000000
#define MOD 1000000007

using namespace std;

int main()
{
    long long i;
    long long n;

    cin >> n;

    i = 1;
    while (i * (i + 1) / 2 < n) i++;

    cout << i << endl;

    return 0;
}
