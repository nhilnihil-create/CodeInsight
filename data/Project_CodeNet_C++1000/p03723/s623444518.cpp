#include <bits/stdc++.h>
using namespace std;


//defines...
#define ll long long
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define mp make_pair
#define in insert
#define pi 2*acos(0.0)1
#define srt(s) sort(s.begin(),s.end())
#define rsrt(s) sort(s.rbegin(),s.rend())
#define all(x) x.begin(),x.end()

const ll mod=1e9+7;
const ll MX=2e5+5;

//code goes from here...



int main()
{
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);
#endif

    boost
    //---------------------------------
    long a, b, c;
    cin >> a >> b >> c;
    if (a > b)
        swap(a, b);
    if (a > c)
        swap(a, c);
    if (b > c)
        swap(b, c);
 
    if ((a == b) & (b == c))
    {
        cout << (a & 1 ? 0 : -1) << endl;
        return 0;
    }
 
    int ans = 0;
    while (((a | b | c) & 1) == 0)
    {
        long na, nb, nc;
        na = (b + c) / 2;
        nb = (c + a) / 2;
        nc = (a + b) / 2;
        a = na;
        b = nb;
        c = nc;
        ans++;
    }
 
    cout << ans << endl;
    
    
    //---------------------------------
    
    return 0;
}
