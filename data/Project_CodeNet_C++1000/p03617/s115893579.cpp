#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int q,h,s,d,n;
    cin>>q>>h>>s>>d>>n;
    long long int ans1=0;
    ans1+=(n/2)*d;
    if (n%2!=0) {
        ans1+=min(q*4,min(h*2,s));
    }
    long long int ans2=s*n;
    long long int ans3=h*2*n;
    long long int ans4=q*4*n;
    cout<<min(ans1,min(ans2,min(ans3,ans4)))<<endl;
}