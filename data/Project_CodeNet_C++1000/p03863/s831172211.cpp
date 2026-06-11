#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{

string s;
cin >> s;
int ln = s.size()-2;
if(s[0]==s[s.size()-1])ln--;
if(ln%2==0)
    cout << "Second" << endl;
else cout << "First" << endl;

  }
