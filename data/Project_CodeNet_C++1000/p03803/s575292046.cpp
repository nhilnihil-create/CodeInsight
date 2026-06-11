#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b;
    if(a==1 || b==1){
        if(a==1 && b==1)cout<<"Draw";
        else if(a<b)cout<<"Alice";
        else if(a>b)cout<<"Bob";

    }
    else {
        if(a>b)cout<<"Alice";
        else if(a==b)cout<<"Draw";
        else if(a<b)cout<<"Bob";
    }



    return 0;
}