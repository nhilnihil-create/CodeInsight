#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#define ll long long int

using namespace std;

int n,a[109];
double sum;

int main()
{
    ///freopen("INA.txt","r",stdin);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>> n;
    for(int i=1;i<=n;i++){
        cin>> a[i];
        sum+=a[i];
    }

    int up = ceil(sum/n);
    int down = floor(sum/n);

    int upsum=0,downsum=0;
    for(int i=1;i<=n;i++){
        upsum+=abs(up-a[i])*abs(up-a[i]);
        downsum+=abs(down-a[i])*abs(down-a[i]);
    }
    cout<< min(upsum,downsum) << endl;
    return 0;
}
