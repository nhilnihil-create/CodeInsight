#include<bits/stdc++.h>
using namespace std;
int arr[100];
int main()
{

    int n,a,c,c1;
    c1=0;
    c=0;
    for(int i=0;i<8;i++)
    {
        arr[i]=0;
    }
    cin>>n;
    for (int i=0;i<n;i++ )
    {
        cin>>a;
        if(a<=399){arr[0]=1;}
        else if(a<=799){arr[1]=1;}
        else if(a<=1199){arr[2]=1;}
        else if(a<=1599){arr[3]=1;}
        else if(a<=1999){arr[4]=1;}
        else if(a<=2399){arr[5]=1;}
        else if(a<=2799){arr[6]=1;}
        else if(a<=3199){arr[7]=1;}
        else{c++;}
    }
    for(int i=0;i<8;i++)
    {
        if(arr[i]==1){c1++;}
    }

    if(c1==0&&c!=0){
        c+=c1;
            c1=1;

    }
else{c+=c1;}



cout<<c1<<" "<<c<<endl;


return 0;

}
