#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c=0,i;
    cin>>a>>b;
    int a1[7]= {1,3,5,7,8,10,12},a2[4]= {4,6,9,11};

    for(i=0; i<4; i++)
    {
        if(a2[i]==a)
            c++;
        if(a2[i]==b)
            c++;
    }
    if(a==2||b==2)
        c=1;
    if(c==0||c==2)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}
