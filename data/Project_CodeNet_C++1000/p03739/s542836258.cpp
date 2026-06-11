#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int wa1=0,wa2=0;
    long long cost1=0,cost2=0;
    for(int i=0;i<n;i++){
        if(i%2==0){
            if(wa1+a[i]<=0){
                cost1+=1-(wa1+a[i]);
                wa1=1;
            }
            else wa1+=a[i];
            if(wa2+a[i]>=0){
                cost2+=wa2+a[i]+1;
                wa2=-1;
            }
            else wa2+=a[i];
        }
        if(i%2){
            if(wa1+a[i]>=0){
                cost1+=(wa1+a[i])+1;
                wa1=-1;
            }
            else wa1+=a[i];
            if(wa2+a[i]<=0){
                cost2+=1-(wa2+a[i]);
                wa2=1;
            }
            else wa2+=a[i];
        }
    }
    cout<<min(cost1,cost2)<<endl;
    return 0;
}