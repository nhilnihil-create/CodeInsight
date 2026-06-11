#define _USE_MATH_DEFINES
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
#include <iterator>
using namespace std;

const long long MAX = 1000000000;

bool query(long long x)
{
    cout << "? " << x << endl;
    char c;
    cin >> c;
    return c == 'Y';
}

int main()
{
    long long n = 0;

    for(int i=0; i<9; ++i){
        int left = 0;
        int right = 9;
        if(i == 0)
            ++ left;

        while(left < right){
            int mid = (left + right) / 2;
            long long x = (n * 10 + mid + 1) * MAX - 1;
            if(!query(x))
                left = mid + 1;
            else
                right = mid;
        }

        n *= 10;
        n += left;

        if(left < 9){
            long long x = n + 1;
            if(query(x)){
                cout << "! " << n << endl;
                return 0;
            }
        }
        else{
            long long x = 10 * n - 1;
            if(!query(x)){
                cout << "! " << n << endl;
                return 0;
            }
        }
    }

    n *= 10;
    cout << "! " << n << endl;
    return 0;
}
