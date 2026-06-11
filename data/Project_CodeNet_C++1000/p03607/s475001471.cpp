#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    unordered_map<int,bool>ump;
    for(int i=0;i<n;i++)
    {
        if(ump.find(v[i])==ump.end()){
            ump[v[i]]=true;
        }
        else
        {
            ump[v[i]]=1-ump[v[i]];
        }
    }
    int count=0;
    for(auto it=ump.begin();it!=ump.end();it++)
    {
        if(it->second==true)
        count++;
    }
    cout<<count;
}