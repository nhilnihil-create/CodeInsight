#include <bits/stdc++.h>
using namespace std;
#define f(i,j,k) for(int i=j;i<k;i++)
int main(){
    long long a,b,c,ans=0,aa,bb,cc;
    cin>>a>>b>>c;
    if(a==b&&b==c&&a%2==0){
        cout<<-1<<endl;
        return 0;
    }
    while(a%2==0&&b%2==0&&c%2==0){
        aa=a/2;
        bb=b/2;
        cc=c/2;
        a=bb+cc;
        b=aa+cc;
        c=aa+bb;
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}