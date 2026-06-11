#include<bits/stdc++.h>

using namespace std;

long long gcd(long long a,long long b)
{
    if(b==0)
        return a;

    return gcd(b,a%b);
}

void test()
{
   long long a,b,x,res;
   cin>>a>>b>>x;

   res=b/x-a/x;
   
   if(a%x==0)
    res++;
   
   cout<<res;

}

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);

    test();

    return 0;
}
