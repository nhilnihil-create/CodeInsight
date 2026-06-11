/**
*    author:  souzai32
*    created: 01.08.2020 16:53:59
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

long long int gcd(long long int a, long long int b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }
}

long long int lcm(long long int a, long long int b)
{
   return a / gcd(a, b) * b;
}
int main() {

    int n;
    cin >> n;
    vector<long long int> t(n);
    rep(i,n) cin >> t.at(i);

    long long int ans=t.at(0);
    rep(i,n-1){
        ans=lcm(ans,t.at(i+1));
    }
    cout << ans << endl;

    return 0;
}