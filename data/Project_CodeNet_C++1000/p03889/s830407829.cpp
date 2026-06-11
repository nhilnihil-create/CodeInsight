#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    string start;
    cin>>start;
    string last=start;
    reverse(last.begin(),last.end());
    for(int i=0;i<last.size();i++)
    {
        if(last[i]=='b') 
        {
            last[i]='d';
        }
        else if(last[i]=='d') 
        {
            last[i]='b';   
        }
        else if(last[i]=='p') 
        {
            last[i]='q';
        }
        else if(last[i]=='q') 
        {
           last[i]='p'; 
        }
    }
    if(last==start) 
    {
     cout<<"Yes";   
     return 0;
    }
    cout<<"No";
}