#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

void half(long long h, long long w, long long *r1, long long *r2)
{
    if ((h*w)%2)
    {
        long long m = max(h,w);
        long long a = min(h,w);
        long long b = m/2 * a;
        *r1 = b;
        *r2 = h*w - b;
    }else
    {
        long long r = h*w/2;
        *r1 = r;
        *r2 = r;
    }
    
    
}

int main()
{
    long long H, W;
    cin >> H;
    cin >> W;
    long long ans = pow(10.0, 5.0);
    long long a,b,c;
    long long he, wi;
    for (int i = 1; i < H; i++)
    {
        he = H - i;
        a = he*W;
        half(H-he, W, &b, &c);
        ans = min(ans, max({a,b,c}) - min({a,b,c}));
    }
    for (int i = 1; i < W; i++)
    {
        wi = W - i;
        a = wi*H;
        half(H, W-wi, &b, &c);
        ans = min(ans, max({a,b,c}) - min({a,b,c}));
    }
    
    cout << ans << endl;
}
