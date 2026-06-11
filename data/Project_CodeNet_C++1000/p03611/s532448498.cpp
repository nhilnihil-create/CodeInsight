#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    vector<pair<int,int>>vp;
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++)
    {
        int element=v[i];
        int count=0;
        bool inside=0;
        while(i<n&&v[i]==element){
            count++;
            i++;
            inside=true;
        }
        if(inside){
            i--;
        }
        vp.push_back({v[i],count});
    }
    int maxresult=0;
    for(int i=0;i<vp.size();i++){
        int result=0;
        result+=vp[i].second;
        if(i<vp.size()-1&&vp[i+1].first==vp[i].first+1){
            result+=vp[i+1].second;
        }
        if(i<vp.size()-1&&vp[i+2].first==vp[i].first+2){
            result+=vp[i+2].second;
        }
        if(result>maxresult){
            maxresult=result;
        }
    }
    cout<<maxresult;
}