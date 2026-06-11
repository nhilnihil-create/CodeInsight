#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
int main()
{
    int A, B;
    cin >> A>>B;

    string ans = "Impossible";
    if(A%3==0) ans = "Possible";
    if(B%3==0) ans = "Possible";
    if((A+B)%3==0) ans = "Possible";
    cout << ans<< endl;

   return 0;
}