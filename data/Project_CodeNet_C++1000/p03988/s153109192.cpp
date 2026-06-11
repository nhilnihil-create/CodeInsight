#include<bits/stdc++.h>
using namespace std;
int n,a[104],num[104],flag=0;
int main(){
    cin>>n;int maxx=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxx=max(maxx,a[i]);
        num[a[i]]++;
    }
    for(int i=maxx;i>maxx/2;i--){
        if(num[i]<2){
            flag=1;
            break;
        }num[i]-=2;
    }
    if((maxx&1)==0){
        if(num[maxx>>1]) num[maxx>>1]--;
        else flag=1;
    }
    if(flag) cout<<"Impossible";
    else{
        for(int i=1;i<=(maxx+1)/2;i++){
            if(num[i]){cout<<"Impossible";return 0;}
        }
        cout<<"Possible";
    }
}