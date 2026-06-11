#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

Int a[220000];
Int n;

int main(){
    cin >> n;
    for(int i = 0;i < n;i++)cin >> a[i];
    sort(a, a+n, [](int x, int y){return x > y;});
    int x = 0;
    while(x+1 < n && a[x+1] >= x+2)x++;
    int up = a[x] - (x+1);
    int r = 0;
    while(x+r+1 < n && a[x+r+1] == x+1)r++;
    if(up % 2 == 0 && r % 2 == 0)cout << "Second" << endl;
    else cout << "First" << endl;
    return 0;
}