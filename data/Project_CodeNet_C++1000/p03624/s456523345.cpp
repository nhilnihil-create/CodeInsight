#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    bool t=false;
    cin>>s;
    for(int i=97;i<=122;i++){
        t=false;
        for(int j=0;j<s.size();j++){
            if(char(i)==s[j])
                t=true;
        }
        if(t==false){
                cout<<char(i);
                return 0;
            }

    }
    if(t==true)
        cout<<"None";

}

