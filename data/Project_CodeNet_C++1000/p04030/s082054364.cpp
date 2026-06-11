#include <bits/stdc++.h>
using namespace std;

int main()  {
    string s,res;
    cin>>s;
    for(auto i:s)   {
        if(i!='B')
            res+=i;
        else if(i=='B' && res.size()>0) {
            res.erase(res.size()-1,1);
        }
    }
    cout<<res;
    return 0;
}
