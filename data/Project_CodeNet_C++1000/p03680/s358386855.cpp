#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
#define f2(i,j,k) for(int i=j;i>k;i--)
using namespace std;
int main(){
    long long n,ans=1,sum=0;
    cin>>n;
    long long a[n+1];
    vector <long long> s(n+1,0);
    f(i,1,n+1){
        cin>>a[i];
    }
    while(ans!=2&&s[ans]==0){
        sum+=1;
        s[ans]++;
        ans=a[ans];
        
    }
    if(ans==2){
        cout<<sum<<endl;
    }
    else{
        cout<<-1<<endl;
    }
    return 0;
}
