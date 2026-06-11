#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int cnt=0;
    while(cnt!=10000&&a%2==0&&b%2==0&&c%2==0){
        int x=a,y=b,z=c;
        a=y/2+z/2;
        b=x/2+z/2;
        c=x/2+y/2;
        cnt++;
    }
    if(cnt==10000)cout<<-1<<endl;
    else cout<<cnt<<endl;
    return 0;
}