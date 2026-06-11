#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <memory.h>
#include <iomanip>
#include <bitset>
#include <list>
#include <stack>

using namespace std;

#define mod 1000000007

int main()
{
    long long int n;
    cin >> n;
    long long int left = 0, right = n;
    while(right - left > 1){
        long long int mid = (left + right) / 2;
        if(mid * (mid + 1) / 2 >= n) right = mid;
        else left = mid;
    }
    // cout << right << endl;
    while(n > 0 && right > 0){
        if(n >= right){
            n -= right;
            cout << right << endl;
        }
        right--;
    }
    return 0;
}