#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    int l[2*n];
    for(int i=0;i<2*n;i++) cin>>l[i];
    for(int i=1;i<2*n;i++){
        int v=l[i];
        int j=i-1;
        while(j>=0&&l[j]>v){
            l[j+1]=l[j];
            j--;
        }
        l[j+1]=v;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        int x=min(l[2*i],l[2*i+1]);
        ans+=x;
    }
    cout<<ans<<endl;
}