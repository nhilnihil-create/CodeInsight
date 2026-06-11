#include <iostream> 
#include <cstdio> 
#include <fstream> 
#include <algorithm> 
#include <cmath> 
#include <deque> 
#include <vector> 
#include <queue> 
#include <string> 
#include <cstring> 
#include <map> 
#include <stack> 
#include <set> 
using namespace std;
typedef long long ll;
ll  abs2(ll a)
{
    if (a >= 0)
        return a;
    else
        return -a;
}

int main()
{
    ll X, Y;
    cin >> X >> Y;
    if (abs2(X - Y) >= 2)
        cout << "Alice\n";
    else
        cout << "Brown\n";
}
