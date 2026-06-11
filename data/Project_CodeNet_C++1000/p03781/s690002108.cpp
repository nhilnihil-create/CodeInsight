#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
const int mod = 1e9+7;
using namespace std;
int main()
{
    long long i;
    int m;
    cin >> m;
    for(i = 1; i*i+i<2*m; i ++);
    cout << i <<endl;
    return 0;
}
