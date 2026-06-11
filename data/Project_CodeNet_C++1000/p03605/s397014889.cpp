#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int main(int argc, char const *argv[])
{
    cin >> n;
    if (n % 10 == 9 || n / 10 == 9) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}