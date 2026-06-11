#include<bits/stdc++.h>
#include<cstring>
using namespace std;
#define ll long long



int main()
{
    ll n;
    cin>>n;
    ll l1[n+1];
    ll x=0,s=0;
    for(int i=1;i<=n;i++){
        cin>>l1[i];
        x+=l1[i];
        //if(i==1&&l1[i]==0&&l1[i+1]<=0)x++,s++,l1[i]=1;
        //else if(i==1&&l1[i]==0&&l1[i+1]>0)x--,s++,l1[i]=-1;
        if(i%2==0){
            if(x-l1[i]<=0&&x<=0){
                s+=(ll)abs(-(x-l1[i])+1-l1[i]);
                //cout<<abs(-(x-l1[i])+1-l1[i])<<endl;
                //l1[i]=l1[i]-x+1;
                x=1;
            }}
            else{
                if(x-l1[i]>=0&&x>=0){
                s+=(ll)abs(-(x-l1[i])-1-l1[i]);
                //cout<<abs(-(x-l1[i])-1-l1[i])<<endl;
                //l1[i]=-(x-l1[i]+1);
                x=-1;
            }
            }
            
        }
        ll s2=s;s=0,x=0;
        for(int i=1;i<=n;i++){
        cin>>l1[i];
        x+=l1[i];
        //if(i==1&&l1[i]==0&&l1[i+1]<=0)x++,s++,l1[i]=1;
        //else if(i==1&&l1[i]==0&&l1[i+1]>0)x--,s++,l1[i]=-1;
        if(i%2!=0){
            if(x-l1[i]<=0&&x<=0){
                s+=(ll)abs(-(x-l1[i])+1-l1[i]);
                //cout<<abs(-(x-l1[i])+1-l1[i])<<endl;
                //l1[i]=l1[i]-x+1;
                x=1;
            }}
            else{
                if(x-l1[i]>=0&&x>=0){
                s+=(ll)abs(-(x-l1[i])-1-l1[i]);
                //cout<<abs(-(x-l1[i])-1-l1[i])<<endl;
                //l1[i]=-(x-l1[i]+1);
                x=-1;
            }
            }
            
        }
    
    cout<<min(s,s2)<<endl;
}
