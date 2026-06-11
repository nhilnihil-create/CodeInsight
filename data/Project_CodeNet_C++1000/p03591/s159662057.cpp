#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
int main()
{
    string s;
    cin >> s;
    

    string ans = "Yes";
    if (s.size()<4) ans="No";
    else if (s.substr(0,4)!="YAKI") ans = "No" ;
    cout << ans<< endl; 

   return 0;
}