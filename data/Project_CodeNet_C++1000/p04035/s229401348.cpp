#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,l;
    cin>>n>>l;
    int a[n];
    int m=0,last;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i){
            if(a[i]+a[i-1]>m){
                m=a[i]+a[i-1];
                last=i;
            }
        }
    }
    
    if(m<l)cout<<"Impossible"<<endl;
    else{
        cout<<"Possible"<<endl;
        for(int i=1;i<last;i++)cout<<i<<endl;
        for(int i=n-1;i>=last;i--)cout<<i<<endl;
    }
    return 0;
}