#include<bits/stdc++.h>
#include<cstring>
using namespace std;
#define ll long long



int main()
{
    string a,b;ll x=0;
    cin>>a;
    cin>>b;
    if(a.size()>b.size())cout<<"GREATER";
    else if(a.size()<b.size())cout<<"LESS";
    else{
        for(int i=0;i<a.size();i++){
            if(a[i]>b[i]){
                cout<<"GREATER";x=2;break;
            }
            else if(a[i]<b[i]){
                cout<<"LESS";x=2;break;
            }
        }
        if(x!=2)cout<<"EQUAL";
    }
}
