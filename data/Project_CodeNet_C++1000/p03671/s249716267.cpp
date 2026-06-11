#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[5],x=0,sum=0;
    for(int i=0; i<3; i++){
        cin>>a[i];
        sum+=a[i];
        if(x<=a[i])x=a[i];
    }
    cout<<sum-x<<endl;
    return 0;

}
