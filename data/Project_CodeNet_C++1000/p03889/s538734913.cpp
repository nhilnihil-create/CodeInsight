#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <algorithm> 
#include<stack>
using namespace std;
stack<char>s;
string k;
int main(){
    cin>>k;
    int lk=k.length();
    for(int i=0;i<lk;i++)
    {
        s.push(k[i]);
    }
    bool flag=1;
    for(int i=0;i<lk;i++)
    {
        char top=s.top();
        if(top=='b') top='d';
        else if(top=='d') top='b';
        else if(top=='p') top='q';
        else if(top=='q') top='p';
        if(top==k[i])
         {
            flag=1;
            s.pop();
        }
        else 
        {
            flag=0;
            break;
        }
    }
    if(flag==0) printf("No");
    else printf("Yes");
    return 0;
}