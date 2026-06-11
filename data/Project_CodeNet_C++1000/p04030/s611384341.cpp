#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    stack<char>s ;
    string str,m;
    cin>>str;
    for(int i=0;i<str.length();i++){
        if(str[i]!='B')
           s.push(str[i]);
        else{
            if(!s.empty())
               s.pop();
        }
    }
    
    while (!s.empty()) 
    { 
       m+= s.top(); 
        s.pop(); 
    } 
    reverse(m.begin(),m.end()); 
    cout<<m;
    return 0;
}
