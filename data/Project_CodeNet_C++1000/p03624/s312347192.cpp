#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(30);
using namespace std;

int main()
{
    IOS;
    string s;
    cin>>s;
    for(char c='a'; c<='z'; c++){
        if(s.find(c)==-1){
            cout<<c;
            return 0;
        }
    }
    cout<<"None";
    return 0;
}
