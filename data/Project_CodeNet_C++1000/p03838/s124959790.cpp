//#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mod=1e9+7;
const int MAXN=1e6+9;
const double eps=1e-8;
const long double pi=3.1415926535897932384626433832795;
const long double e=2.71828182845904523536028747135266;
int a[MAXN];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t=1;
    while(t--){
        int x,y;
        cin >> x >> y;
        int a=abs(x+y)+1;
        int b=abs(x-y);
        if(x>=y) b+=2;
        cout << min(a,b) << endl;
    }
    return 0;
}


