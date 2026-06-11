#include<bits/stdc++.h>

using namespace std;

void test()
{
   int a,b,c;

   map<int,int>mp;
   int res=0;
   cin>>a>>b>>c;

   mp[a]++;
   mp[b]++;
   mp[c]++;

   for(int i=1;i<=100;i++)
   {
       if(mp[i])
        res++;
   }

   cout<<res<<"\n";

}

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);

    test();

    return 0;
}
