#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m;
    cin>>n;
    vector<int>a(n);
    if(n%2==0){
        for(int i=0;i<n;i++){
            cin>>m;
            if(i%2==1)a[n/2-i/2-1]=m;
            if(i%2==0)a[n/2+i/2]=m;
        }
    }else{
        for(int i=0;i<n;i++){
            cin>>m;
            if(i%2==0)a[n/2-i/2]=m;
            if(i%2==1)a[n/2+i/2+1]=m;
        }
    }
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    return 0;
}