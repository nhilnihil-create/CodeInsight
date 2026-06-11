#include <bits/stdc++.h>
using namespace std;
struct point{double x;double y;};
int i,j,k,count1=0,count2=0;

int main(){
    int a,b,c,a2,b2,c2;
    cin>>a>>b>>c;
    if(a==1&&b==1&&c==1)cout<<0<<endl;
    else if(a==b&&c==a)cout<<-1<<endl;
    else{
        int ans=0;
        while(a%2==0&&b%2==0&&c%2==0){
            ans++;
            a2=(b+c)/2;
            b2=(a+c)/2;
            c2=(a+b)/2;
            a=a2;
            b=b2;
            c=c2;
        }
        cout<<ans<<endl;
    }
}