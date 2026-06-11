#include <bits/stdc++.h>
using namespace std;
struct point{double x;double y;};
int i,j,k,count1=0,count2=0;

int main(void){
    long long int q,h,s,d,n,ans=0,k;
    cin>>q>>h>>s>>d>>n;
    n*=4;
    vector<pair<int,int>> list(4);
    list[0]=make_pair(8*q,1);
    list[1]=make_pair(4*h,2);
    list[2]=make_pair(2*s,4);
    list[3]=make_pair(d,8);
    sort(list.begin(),list.end());
    for(i=0;i<4;i++){
        k=n/list[i].second;
        n=n%list[i].second;
        if(list[i].second==1)ans+=k*q;
        if(list[i].second==2)ans+=k*h;
        if(list[i].second==4)ans+=k*s;
        if(list[i].second==8)ans+=k*d;
    }
    cout<<ans<<endl;
}