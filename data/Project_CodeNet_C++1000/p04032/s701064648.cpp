#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
string s;
cin >> s;
if(s.size()<=2)
{
    if(s[0]==s[1])
        cout << 1 << " " << 2 << endl;
    else
     cout << -1 << " " << -1 << endl;
     return 0;
}
bool mrk = 0 ;
int lf , rt ;
for(int i=1; i<s.size()-1; i++)
{
    if(s[i]==s[i+1] && s[i]==s[i-1])
    {
        lf = i-1;
        rt = i+1;
        mrk = 1;
        break;
    }
    else if(s[i]==s[i+1] && s[i]!=s[i-1])
    {
         lf = i-1;
        rt = i+1;
        mrk = 1;
        break;

    }
    else if(s[i-1]==s[i+1] && s[i]!=s[i-1])
    {
         lf = i-1;
        rt = i+1;
        mrk = 1;
        break;
    }
    else if(s[i]==s[i-1] && s[i]!=s[i+1])
    {
         lf = i-1;
        rt = i+1;
        mrk = 1;
        break;

    }

}
if(mrk)
{
    cout << lf+1 << " " << rt+1 << endl;
}
else
    cout << -1 << " " << -1 << endl;


 }
