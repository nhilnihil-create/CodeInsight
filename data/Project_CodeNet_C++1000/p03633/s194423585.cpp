#include<bits/stdc++.h>
using namespace std;

unsigned long long gcd(unsigned long long a, unsigned long long b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }
}

unsigned long long lcm(unsigned long long a, unsigned long long b)
{
   return a / gcd(a, b) *b;
}

int main(){
    int n;
    cin >> n;
    unsigned long long ans=0;
    for(int i=0;i<n;i++){
        unsigned long long a;
        cin >> a;
        if(i==0)ans=a;
        ans=lcm(ans,a);
    }
    cout << ans << endl;
    return 0;
}