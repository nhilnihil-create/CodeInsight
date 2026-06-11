#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x=0,y=0;
    char ch;
    cin>>n;
    getchar();
    while(n--)
    {
        cin>>ch;
        if(ch=='I')
            x++;
        else if(ch=='D')
            x--;
        y=max(y,x);
    }
    cout<<y<<endl;
    return 0;
}
