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
   string s;
   cin>>s;

   int pcount=0;
   for(auto x:s)
   {
       if(x=='p')
        pcount++;
   }

   cout<<s.size()/2-pcount<<"\n";

}

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);

    test();

    return 0;
}
