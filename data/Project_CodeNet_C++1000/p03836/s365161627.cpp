#include <bits/stdc++.h>

#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
#define int long long
#define endl '\n'

using namespace std;

const int N = 2e5 + 77;

int32_t main()
{
    fast;
    int a , b ;cin >> a >> b;
    int x, y ; cin >>x >> y ;
    string ans = "";
    string p1="" , p2="" , p3="",p4="";
    p1 += string(abs(x-a),'R');
    p1 += string(abs(b-y),'U');
    for(char i : p1){
        if(i=='R') p2 += 'L';
        else if(i=='U') p2 += 'D';
    }
    p3 += "DR";
    p3 += p1;
    p3 += "UL";

    p4 += "UL";
    p4 += p2;
    p4 += "DR";
    
    ans += p1 ;
    ans += p2;
    ans += p3;
    ans += p4;
    cout << ans << endl;
    return 0;
}