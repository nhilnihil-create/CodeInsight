#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    int n,a[1005],ans1=0,ans2=0;
    int c[15]={};
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        if(1<=a[i] && a[i]<=399 && c[1]!=1){
            c[1]=1;
            ans1++;
            ans2++;
        }
        if(400<=a[i] && a[i]<=799 && c[2]!=1){
            c[2]=1;
            ans1++;
            ans2++;
        }
        if(800<=a[i] && a[i]<=1199 && c[3]!=1){
            c[3]=1;
            ans1++;
            ans2++;
        }
        if(1200<=a[i] && a[i]<=1599 && c[4]!=1){
            c[4]=1;
            ans1++;
            ans2++;
        }
        if(1600<=a[i] && a[i]<=1999 && c[5]!=1){
            c[5]=1;
            ans1++;
            ans2++;
        }
        if(2000<=a[i] && a[i]<=2399 && c[6]!=1){
            c[6]=1;
            ans1++;
            ans2++;
        }
        if(2400<=a[i] && a[i]<=2799 && c[7]!=1){
            c[7]=1;
            ans1++;
            ans2++;
        }
        if(2800<=a[i] && a[i]<=3199 && c[8]!=1){
            c[8]=1;
            ans1++;
            ans2++;
        }
        if(3200<=a[i]){
            ans2++;
        }
        if(3200<=a[i] && ans1==0){
            ans1++;
        }
    }   
    cout<<ans1<<" "<<ans2<<endl;
    return(0);
}