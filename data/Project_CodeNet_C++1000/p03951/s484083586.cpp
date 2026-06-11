#include <bits/stdc++.h>
using namespace std;
struct point{double x;double y;};
int i,j,k,count1=0,count2=0;

int main(void){
    int n,ans;
    string s,t;
    cin>>n>>s>>t;
    ans=0;
    for(i=1;i<=n;i++){
        if(s.substr(n-i,i)==t.substr(0,i)){
            ans=i;
        }
    }
    cout<<2*n-ans<<endl;
}