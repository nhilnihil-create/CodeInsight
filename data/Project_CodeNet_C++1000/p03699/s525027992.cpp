#include<iostream>
#include<algorithm>
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
    sort(v.begin(),v.end());
    int sum=0;
    for(int i=0;i<v.size();i++)
    {
        sum+=v[i];
    }
    int nonten=sum;
    for(int i=0;i<v.size();i++){
        if(v[i]%10!=0){
            nonten=v[i];
            break;
        }
    }
    int result1=sum-nonten;
    int index=0;
    while(index<v.size()&&sum%10==0){
        sum-=v[index];
        index++;
    }
    cout<<max(sum,result1);
}