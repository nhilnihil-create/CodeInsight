#include<bits/stdc++.h>
#define int long long
#define dd second
#define mp make_pair
#define pb push_back
#define ff first
#define dd second
#define pp pair<int,int>
using namespace std;
int h,w,d;
string tt = "RGBY";
main()
{
    ios_base::sync_with_stdio(false); cin >> h >> w >> d;
    for(int y = 1; y <= h; ++y)
    {
        for(int x = 1; x <= w; ++x)
        {
            int a = (x+y+500)/d;
            int b = (x-y+500)/d;
            cout << tt[2*(a%2)+b%2];
        }
        cout << endl;
    }
}

