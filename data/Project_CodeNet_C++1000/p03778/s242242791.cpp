#include<bits/stdc++.h>
using namespace std;
#define Mod(n) n % 1000000007
const int dx[8] = {1, 0, -1, 0, -1, 1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, -1, -1, 1};

int main()
{
    int W,a,b;
    cin >> W >> a >> b;
    if(a > b)
    {
        int tmp = b;
        b = a;
        a = tmp;
    }
    cout << (b - a - W > 0 ? b - a - W : 0 )  << '\n';
}
