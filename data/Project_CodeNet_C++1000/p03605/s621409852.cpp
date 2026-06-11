#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int N;
    cin>>N;
    if(N%10==9)
        cout<<"Yes"<<endl;
    else if(N>=90 && N<=99)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}
