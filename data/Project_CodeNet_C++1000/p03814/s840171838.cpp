#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{


string s;
cin >> s;
int pa = -1 ,c = 0 ;
for(int i=0; i<s.size(); i++)
{
    if(pa==-1 && s[i]=='A')
        pa = i;
    if(s[i]=='Z')c = i;
}

cout << c - pa + 1 << endl;



}
