#include<iostream>
#define MOD 1000000007LL
using namespace std;
int main(){
    long long n,ans=0LL;
    bool f0,f1;
    string s1,s2;
    cin>>n>>s1>>s2;
    ans=((f0=s1[0]==s2[0])?3LL:6LL);
    for(int i=1+!f0;i<n;i+=(f1?1:2),f0=f1){
        f1=(s1[i]==s2[i]);
        ans*=(f0?2LL:f1?1LL:3LL);
        ans%=MOD;
    }
    cout<<ans<<endl;
    return 0;
}