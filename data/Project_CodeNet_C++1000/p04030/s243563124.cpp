#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
 string s;
 cin >> s;
 string ans = "" ;
 int cnt = 0;
 for(int i=s.size()-1; i>=0; i--)
 {
     if(!cnt && s[i]!='B')
        ans += s[i];
     else if(cnt && s[i]!='B')
     {
         cnt--;
     }
     else if(s[i]=='B')
        cnt++;
 }
 reverse(ans.begin(),ans.end());
 cout << ans << endl;

 }
