#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<a.size();i++)
    {
        cin>>a[i];
    }
    int index=a.size()-1;
    while(index>=0){
        cout<<a[index]<<" ";
        index-=2;
    }
    index=1;
    if(a.size()%2==0)
        index=0;
    while(index<a.size()){
        cout<<a[index]<<" ";
        index+=2;
    }
    
}