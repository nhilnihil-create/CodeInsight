#include <bits/stdc++.h>

using namespace std;

int main()
{
   string st; cin>>st;
   int ret = 0;
   for(int i=0;i+1<st.size();++i){
       if(st[i]!=st[i+1])ret++;
   }
   cout<<ret<<"\n";
   
   return 0;
}