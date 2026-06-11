#include <iostream>
using namespace std;
int main()
{
    int g=0;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='g')
            g++;
        else
            g--;
    }
    cout<<g/2<<endl;
    return 0;
}
