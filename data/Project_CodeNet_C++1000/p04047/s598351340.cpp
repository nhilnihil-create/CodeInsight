#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a;
    cin>>a;
    a=2*a;
    int s[a];
    for(int i=0;i<a;i++){
        cin>>s[i];
    }
    sort(s,s+a);
    int sum=0;
    for(int i=0;i<a;i+=2){
        sum+=s[i];
    }
    cout<<sum<<'\n';
}
