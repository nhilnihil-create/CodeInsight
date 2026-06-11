#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;

#define dbg(x1) cout<<#x1<<" = "<<(x1)<<endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<(x1)<<" "<<#x2<<" = "<<(x2)<<endl
#define dbg3(x1,x2,x3) cout<<#x1<<" = "<<(x1)<<" "<<#x2<<" = "<<(x2)<<" "<<#x3<<" = "<<(x3)<<endl

int main() {
    //freopen(".in", "r", stdin);
    int n;
    scanf("%d",&n);
    ll sum=0;
    for(int i=1;;i++)
    {
        sum+=i;
        if(sum>=n) return 0*printf("%d\n",i);
    }
    return 0;
}
