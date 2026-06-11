#include <iostream> 
#include <string> 
#include <vector> 
#include <cmath> 
#include <algorithm> 
#include <cstdlib> 
#include <ctime> 
#include <cstdio> 
#include <functional> 
#include <set> 
#include <sstream> 
#include <cctype>
#include <stack>
#include <queue>
#include <cstring>
#include <map>
#include <list>
#include <cassert>
#include <climits>

using namespace std;

int main()
{
    int n, k, x, y;
    cin >> n >> k >> x >> y;

    if (n >= k) {
        cout << (k * x) + ((n - k) * y);

    }
    else {
        cout << (n * x);
    }
    
}