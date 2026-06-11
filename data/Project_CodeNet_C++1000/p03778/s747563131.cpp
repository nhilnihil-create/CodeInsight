#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int w,a,b;
    cin>>w>>a>>b;
    int x=min(a,b);
    int y=max(a,b);
    ((y-(x+w))>0)?cout<<(y-(x+w))<<endl:cout<<0<<endl;

}
