#include <iostream>
#include<bits/stdc++.h>
#include <string>
#define loop(i,n) for(int i=0;i<(int)n;i++)

using namespace std;


int main()
{

string s;
cin>>s;

string ans;

for(int i=0;i<s.size();i++){

    if(s[i]=='B'){
        if(ans.size()==0)
            continue;

        else
            ans.erase(ans.size()-1);
    }
    else{

        ans=ans+s[i];
    }

}

cout<<ans;

}


