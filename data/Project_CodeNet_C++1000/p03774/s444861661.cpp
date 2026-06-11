#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>v1(n);
    vector<pair<int,int>>v2(m);
    for(int i=0;i<n;i++)
    {
        int f,s;
        cin>>f>>s;
        v1[i].first=f;
        v1[i].second=s;
    }
    for(int i=0;i<m;i++)
    {
        int f,s;
        cin>>f>>s;
        v2[i].first=f;
        v2[i].second=s;
    }
    for(int i=0;i<n;i++)
    {
        int fcor=v1[i].first;
        int scor=v1[i].second;
        int min=INT_MAX;
        int  index;
        for(int j=0;j<m;j++){
            if((abs(fcor-v2[j].first)+abs(scor-v2[j].second))<min){
                min=(abs(fcor-v2[j].first)+abs(scor-v2[j].second));
                index=j;
            }
        }
        cout<<index+1<<endl;
    }

}