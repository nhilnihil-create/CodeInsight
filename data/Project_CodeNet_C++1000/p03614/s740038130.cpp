#define loop(i,j,k) for(long long i = j;i < k;i++)

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstdint>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

int main(void) {
    int n,p[100001];
    cin>>n;
    loop(i,0,n)cin>>p[i];
    int prev = 0;
    int res = 0;
    p[n] = -1;
    loop(i,0,n+1) {
        if(p[i] == i+1) {
            prev++;
        }
        else if(prev != 0) {
            res += (prev +1)/2;
            prev = 0;
        }
    }
    cout << res << endl;
}
