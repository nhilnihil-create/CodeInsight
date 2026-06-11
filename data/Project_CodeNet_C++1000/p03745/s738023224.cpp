#include<bits/stdc++.h>
using namespace std;   
int main(){
    int n,a[100005],ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int c=0,d=0;
    for(int i=0;i<n-1;i++){
        if(d==0){
            if(a[i]==a[i+1]){
                continue;
            }
            if(a[i]<a[i+1]){
                d=1;
            }
            else{
                d=2;
            }
        }
        if(d==1 && a[i]>a[i+1]){
            ans++;
            d=0;
        }
        if(d==2 && a[i]<a[i+1]){
            ans++;
            d=0;
        }
    }
    cout<<ans+1<<endl;
    return 0;
}