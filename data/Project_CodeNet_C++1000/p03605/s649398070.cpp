#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    cout << (n %10 == 9 || n / 10 == 9 ? "Yes" : "No") << endl;

}