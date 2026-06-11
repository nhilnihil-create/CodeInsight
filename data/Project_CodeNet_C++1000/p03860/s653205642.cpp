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
   string a,b,c;
   cin>>a>>b>>c;

   cout<<"A"<<b[0]<<"C";

}

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);

    test();

    return 0;
}
