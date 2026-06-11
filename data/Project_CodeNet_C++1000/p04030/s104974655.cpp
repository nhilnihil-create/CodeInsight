#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
string s,an="";

cin>>s;
for(auto i: s)
{
    if(i=='B'&&an.size())an.pop_back();
    else if(i!='B')an.push_back(i);
}
cout<<an<<endl;
    
}