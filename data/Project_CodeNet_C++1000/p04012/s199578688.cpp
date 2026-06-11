#include <iostream>

#include <map>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;
//const char a[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};



void solver() {
    string s;
    cin>>s;
    unordered_map<char,int> ele;
    for(int i=0;i<s.size();i++)
    {
        ele[s[i]]++;
    }
    bool my=true;
    for(auto i:ele)
    {
        if(i.second%2==1)
        {
            my=false;
        }
    }
    if(my)
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
























}


int main() {
    int n=1;
    //cin>>n;
    while(n--)
    {
        solver();
    }
}
