#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int cnt=-1,sum=0;
    for(int i=0;sum<t;i++){
        sum+=i;
        cnt++;
    }
    cout<<cnt<<'\n';
}
