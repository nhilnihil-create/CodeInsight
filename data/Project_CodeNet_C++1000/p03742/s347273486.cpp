#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define MOD 1000000007
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec; typedef pair<int, int> pi;
int dd[] = { 0, 1, 0, -1, 0 };
#define all(u) begin(u),end(u)
#define mp make_pair
#define pb push_back

int main()
{
   i64 x, y;
    cin >> x >> y;
    cout << (abs(x - y) >= 2 ? "Alice" : "Brown") << endl;
    return 0;
    
    
    
    
    if(x >=3 || y >= 3)
    {
        cout << "Alice" << endl;
        return 0;
    }
    bool b = false;
    while(x  > 1 || y > 1)
    {
        if(x > 1)
        {
            x -= 2;
            y += 1;
        }
        else
        {
            y -= 2;
            x += 1;
        }
        b = !b;
    }
    cout << (b ? "Alice" : "Brown") << endl;
  return 0;
}
