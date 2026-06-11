#include<bits/stdc++.h>
#define speed_up ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define ara(A,N) sort(A,A+N)
#define rev(A,N) sort(A,A+N,greater<long long>())
using namespace std;
int main()
{
    speed_up;
    int w, h, n, a;
    cin>>w>>h>>n;
    int lx = 0, rx = w, uy = h, dy = 0, x, y;
    while(n--)
    {
        cin>>x>>y>>a;
        if(a == 1) lx = max(lx, x);
        if(a == 2) rx = min(rx, x);
        if(a == 3) dy = max(dy, y);
        if(a == 4) uy = min(uy, y);
    }

    int b, c;
    b = max(0, rx - lx);
    c = max(0, uy - dy);

    cout<<b*c<<endl;


    return 0;

}
