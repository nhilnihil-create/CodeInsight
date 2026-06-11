#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main(){
    unsigned long long int n;
    cin>>n;
    vector<unsigned long long int >v(n);
    map<unsigned long long int,unsigned long long int>mp;
    for(unsigned long long int i=0;i<n;i++)
    {
        cin>>v[i];
        if(mp.find(v[i])==mp.end()){
            mp[v[i]]=1;
        }
        else{
            mp[v[i]]++;
        }
    }
    unsigned long long int first=0;
    unsigned long long int second=0;
    unsigned long long int area=0;
    for(auto it=mp.rbegin();it!=mp.rend();it++){
        if(it->second>=4&&area==0){
            area=(it->first)*(it->first);
            if(first==0){
                break;
            }
            else
            {
                if(area<first*it->first){
                    area=first*it->first;
                    break;
                }
            }
        }
        else
        if(it->second>=2){
            if(first==0){
                first=it->first;
            }
            else
            if(second==0){
                second=it->first;
                if(area<first*second){
                    area=first*second;
                }
                break;
            }
        }
    }
    cout<<area;
}