#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
#define f2(i,j,k) for(int i=j;i>k;i--)
using namespace std;
int main(){
    long long a,b,c,f;
    cin>>a>>b>>c;
    f=a;
    vector <long long> d(b,0);
    while(d[f%b]==0){
        d[f%b]++;
        f+=a;
    }
    if(d[c]==0){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
    }
    return 0;
}
