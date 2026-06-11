#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <math.h>
#include <utility>
#include <vector>
#include <map>
#include <cstdlib>
#define div1 1000000007
const long long INF = 1LL << 60;
using namespace std;
// a>b -> a==b;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// a<b -> a==b;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main(void)
{
    long long N, max=1, i=2, del, sum=0, j;

    cin >> N;

    while(N > max){
        max += i;

        i++;
    }
    
    i--;

    for(j=1; j<=i; j++){
        sum += j;
    }

    del = sum - N;

    for(j=1; j<=i; j++){
        if(j != del){
            cout << j << endl;
        }
    }

    return 0;
}