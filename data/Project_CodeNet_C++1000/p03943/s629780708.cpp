#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int a, b ,c;
    cin >> a >> b >> c;
    if(a+b+c==max({a, b, c})*2)cout << "Yes";
    else cout<< "No";
}

