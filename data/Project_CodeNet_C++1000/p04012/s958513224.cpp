

#include<bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false) , cin.tie(NULL) , cout.tie(NULL);

int main()
{
    speed;

    string s;
    cin>>s;

    unordered_map<char,int>m;

    for(int i=0;i<s.size();i++) m[s[i]]++;

    int flag=0;
    
    for(auto i : m) 
    {
        if(i.second%2!=0)
        {
            flag=1;
            break;
        }
    }

    if(flag) cout<<"No"<<"\n";
    else cout<<"Yes"<<"\n";
}