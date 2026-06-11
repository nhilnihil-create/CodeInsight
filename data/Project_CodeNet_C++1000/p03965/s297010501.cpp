#include<iostream>
#include<string>
using namespace std;
int main(){
    string a;
    cin>>a;
    int len=a.size();
    int i;
    int x=0,y=0,ans=0;
    for(i=0;i<len;i++)
        if(x==y){x++;if(a[i]=='p') ans--;}
        else{y++;if(a[i]=='g') ans++;}
    cout<<ans<<endl;
    return 0;
}