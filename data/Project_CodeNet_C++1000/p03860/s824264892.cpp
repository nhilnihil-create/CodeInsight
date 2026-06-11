#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    string s;
    getline(cin,s);
    char c ;
    bool mrk  = 0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]==' ')
            mrk = 1;
        if(s[i]!=' ' && mrk)
            {c = s[i];break;}
    }
    cout << "A" << c <<  "C" << endl;
}
