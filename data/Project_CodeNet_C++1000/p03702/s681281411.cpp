#include <bits/stdc++.h>
using namespace std;
const int Max=1e5+10;
int h[Max];
int n,a,b;
bool check(long long x){
    //cout<<x<<"!!!!!!!!!!";
    long long base=x*b;
    long long cnt=0;
    for(int i=1;i<=n;i++){
        if(h[i]>base){
            cnt+=((h[i]-base)/(a-b));
            if((h[i]-base)%(a-b)){
                cnt++;
            }
            if(cnt>x){
                return 0;
            }
        }
    }
    //cout<<cnt<<endl;
    return 1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>a>>b;
    long long l=0,r=0;
    for(int i=1;i<=n;i++){
        cin>>h[i];
        r+=h[i]/a;
        if(h[i]%a){
            r++;
        }
    }
    sort(h+1,h+1+n);
    while(l<=r){
        long long mid=l+r>>1;
        if(check(mid)){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<l<<endl;
    return 0;
}