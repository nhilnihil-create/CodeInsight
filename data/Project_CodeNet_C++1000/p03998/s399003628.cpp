#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str[3];
    cin>>str[0]>>str[1]>>str[2];
    int p=0,c;
    while(1)
    {
        if(str[p].empty())
        {
            cout<<(char)(p+'A')<<endl;
            break;
        }
        c=p;
        p=str[p][0] - 'a';
        str[c].erase(str[c].begin());
    }

    return 0;
}
