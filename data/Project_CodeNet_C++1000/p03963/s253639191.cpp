#include<bits/stdc++.h>

using namespace std;

void test()
{
   int n,k;
   cin>>n>>k;

   long long res=k;

   for(int i=1;i<n;i++)
   {
       res*=(k-1);
   }

   cout<<res<<endl;
}

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);

    test();

    return 0;
}
