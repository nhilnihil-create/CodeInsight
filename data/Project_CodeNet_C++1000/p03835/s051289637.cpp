
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a , b ;
    cin>>a>>b;
    int t=0 , n;
    for (int x=0 ; x<=a ; ++x)
    {
        for (int y=0 ; y<=a ; ++y)
        {
            n=b-x-y;
            if (n>=0&&n<=a)
            {
                t+=1;
            }
        }
    }
    cout<<t<<endl;
}
