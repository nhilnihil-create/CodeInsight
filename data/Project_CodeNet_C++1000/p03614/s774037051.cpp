#include <iostream>

using namespace std;
int x,nr,nr1,i,n;
int main()
{
    cin>>n;
    nr1=0;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        if(x==i) nr1++;
        else
        {
            nr+=(nr1+1)/2;
            nr1=0;
        }
    }
    nr+=(nr1+1)/2;
    cout<<nr;
    return 0;
}
