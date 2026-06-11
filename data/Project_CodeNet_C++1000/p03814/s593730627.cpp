#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a=0,b=0;
    string s;
    cin>>s;
    a=s.find("A");
    if(a>0)
    s=s.substr(a);
    for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='Z'){
                b=i;
            break;
            }

    }
    cout<<b+1;

       return 0;
}
