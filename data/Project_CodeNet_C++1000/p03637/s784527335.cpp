#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<utility>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#define EPS 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LL long long
const int MOD = 1E9+7;
const int N = 200000+5;
const int dx[] = {-1,1,0,0,-1,-1,1,1};
const int dy[] = {0,0,-1,1,-1,1,-1,1};
using namespace std;

int main() {
    LL n,modFour=0,modTwo=0;
    cin >> n;
    for(LL i=0;i<n;i++)
    {
        LL a; cin >> a;
        if(a%4==0)
            modFour++;
        else if(a%2==0)
            modTwo++;
    }
    LL count = modFour+(modTwo/2);
    if(count>=n/2)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}



