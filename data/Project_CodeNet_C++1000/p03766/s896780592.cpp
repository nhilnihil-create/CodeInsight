#include<bits/stdc++.h>

using namespace std;

#define ll  long long
#define ld  double

#define all(x)  x.begin(),x.end()
#define sz(x)   (int)x.size()

#define pb  emplace_back
#define X   first
#define Y   second

const int   N   = 1e6 + 5;
const int   mod = 1e9 + 7;

void add(int &a,int b)  {
    a += b;
    if (a >= mod)
        a -= mod;
}
void sub(int &a,int b)  {
    a -= b;
    if (a <  0)
        a += mod;
}
int mul(int a,int b)    {
    return  1ll * a * b % mod;
}
int Pow(int a,int b)    {
    int ans = 1;
    while (b)   {
        if(b & 1)   ans = mul(ans,a);
        a = mul(a,a);   b >>= 1;
    }
    return  ans;
}
int inv(int a,int p)    {
    return  a == 1 ? 1 : p - 1ll * p * inv(p % a,a) / a;
}

typedef pair<int,int>   ii;

int f[N];

int main()  {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;  cin >> n;

    f[0] = 1;
    f[1] = 1;

    int S = 2;

    for(int i = 2 ; i < n ; ++i)    {
        add(f[i],S);
        sub(f[i],f[i - 2]);

        add(S,f[i]);
    }
    sub(S,f[n - 1]);

    int ans = 1;

    add(ans,mul(S,n - 1));
    add(ans,mul(f[n - 1],n - 1));

    for(int i = 0 ; i < n - 1 ; ++i)    {
        int C = f[i];
        C = mul(C,n - 1);
        C = mul(C,n - 1);

        add(ans,C);
    }
    cout << ans << endl;
}