#include <bits/stdc++.h>
using namespace std;
int main()
{

   int a,b;
   cin>>a>>b;
if((a==1||a==5||a==7||a==3||a==10||a==12||a==8)&&(b==1||b==5||b==7||b==3||b==10||b==12||b==8))
    {
        cout<<"Yes"<<endl;
    }

else if((a==4||a==6||a==9||a==11)&&(b==4||b==6||b==9||b==11))
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    return 0;
}



