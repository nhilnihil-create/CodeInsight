/**
*    author:  souzai32
*    created: 14.08.2020 14:58:45
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

long long gcd(long long a, long long b)
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

long long lcm(long long a, long long b)
{
   return a * b / gcd(a, b);
}

int main() {

    int n,k;
    cin >> n >> k;
    vector<long long> a(n);
    rep(i,n) cin >> a.at(i);
    sort(a.begin(),a.end());
    string ans="POSSIBLE";

    if(k>a.at(n-1)) ans="IMPOSSIBLE";
    else if(n!=1){
        long long num=gcd(a.at(0),a.at(1));
        for(int i=2; i<n; i++){
            num=gcd(num,a.at(i));
        }
        if(k%num) ans="IMPOSSIBLE";
    } 
    else if(k!=a.at(0)) ans="IMPOSSIBLE";

    cout << ans << endl;

    return 0;
}