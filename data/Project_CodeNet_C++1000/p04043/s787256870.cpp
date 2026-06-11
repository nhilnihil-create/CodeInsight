#include<iostream>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;

     if((a+b+c)==17)
     {
         if(a!=5  && a!=7)
            goto jump;
         else if(b!=5 && b!=7)
            goto jump;
                else if(c!=5 && c!=7)
                goto jump;
     else
        cout<<"YES\n";
        return 0;
     }
    else {
            cout<<"NO\n";
            return 0;
    }
    jump:
        cout<<"NO\n";

}
