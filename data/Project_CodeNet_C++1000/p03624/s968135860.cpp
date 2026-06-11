#include<bits/stdc++.h>
using namespace std;

main()
{
   // ios::sync_with_stdio(0);
   // cout.tie(0);
   // cin.tie(0);
    long long i,j,k,l,m,n,o,p;
 string s;
 while(cin>>s){
    l=s.size();
    int x[150]={0};
    for(i=0;i<l;i++)x[s[i]]++;
    l=0;
    for(i=97;i<123;i++)if(x[i]==0){l++;
        printf("%c\n",i);
        break;
    }
    if(l==0)cout<<"None"<<endl;
 }
    return 0;

}
