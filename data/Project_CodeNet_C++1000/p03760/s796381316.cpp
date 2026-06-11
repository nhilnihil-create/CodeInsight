#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    bool chk=true;
    string O,E;
    cin >> O >> E;
    if(O.size()!=E.size())
    {
        chk=false;
    }
    for(int i=0; i<O.size(); i++)
    {
        cout << O.at(i);
        if(i==O.size()-1&&chk==false) {break;}
        cout << E.at(i);
    }
    cout << endl;
}