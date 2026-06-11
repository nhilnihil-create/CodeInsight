#include<bits/stdc++.h>
using namespace std;
#define Fastread ios_base::sync_with_stdio(false);
int main()
{
    Fastread;
    cin.tie(NULL);
    int a,b;
    cin>>a>>b;
    if(a==b){
        cout<<"Draw"<<endl;
    }
    else if(a==1 || b==1){
        if(a==1){
            cout<<"Alice"<<endl;
        }
        else{
            cout<<"Bob"<<endl;
        }
    }
    else if(a > b){
        cout<<"Alice"<<endl;
    }
    else{
        cout<<"Bob"<<endl;
    }
    return 0;
}

