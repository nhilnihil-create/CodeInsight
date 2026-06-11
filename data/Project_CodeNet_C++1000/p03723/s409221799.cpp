#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)

using ll=long long;
using namespace std;

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int s,t;
    int i=0;
    bool flag=true;
    if(a%2==1 || b%2==1 || c%2==1) cout<<0<<endl;
    else if(a==b && b==c) cout<<-1<<endl;
    else{
        while(flag){
            s=a;
            t=b;
            a=b/2+c/2;
            b=s/2+c/2;
            c=s/2+t/2;
            i++;
            if(a%2==1 || b%2==1 || c%2==1) flag=false;
        }
        cout<<i<<endl;
    }
    
    return 0;
}