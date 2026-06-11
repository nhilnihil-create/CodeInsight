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
    int numm[105];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {   
        int temp;
        cin >> temp;
        numm[i] = temp;

    }
    
    int mincost = INT_MAX;


    for (int i = -100; i < 101; i++)
    {
        int cost = 0;
        for (int j = 0; j < n; j++)
        {
            cost += ((numm[j] - i) * (numm[j] - i));

        }
        if (cost < mincost) mincost = cost;

    }
    cout << mincost;
}