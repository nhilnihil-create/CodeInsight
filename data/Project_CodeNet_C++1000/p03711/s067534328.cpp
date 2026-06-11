#include<bits/stdc++.h>
typedef long long int lli;
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int a,b,temp=0;
    cin>>a>>b;
    if(a==b)
    temp=1;
    else if(a==2 || b==2)
    temp=0;
    else if(a==4 || a==6 || a==9 || a==11)
    {
        if(b==4 || b==6 || b==9 || b==11)
        temp=1;
    }
    else
    {
        if(b==1 || b==3 || b==5 || b==7 || b==8 || b==10 || b==12 )
        temp=1;
    }
    if(temp)
    cout<<"Yes";
    else
    cout<<"No";

	return 0;
}