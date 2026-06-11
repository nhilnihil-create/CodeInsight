#include <iostream>

using namespace std;

int main()
{
    string s[101];
    int h,w,i;
    cin>>h>>w;

    for(i=0; i<h; i++)
    {
        cin>>s[i];
    }
    for(i=0; i<w+2; i++)
    {
        cout<<"#";
    }cout<<endl;

    for(i=0; i<h; i++)
    {
        cout<<"#"<<s[i]<<"#"<<'\n';
    }
    for(i=0; i<w+2; i++)
    {
        cout<<"#";
    }cout<<endl;

    return 0;
}
