#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
int main()
{
    string s;
    cin>>s;

    string ss = "CODEFESTIVAL2016";
    
    int cnt=0;
    for (int i = 0; i < ss.size(); i++){
        if(s[i]!=ss[i]) cnt++;
    }

    cout << cnt << endl;

   return 0;
}