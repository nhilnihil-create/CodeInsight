#include<bits/stdc++.h>
using namespace std;
#define int long long
void Digvijay()
{
   int n;
   cin>>n;
   vector<int> a(n);
   for(auto& it:a)cin>>it;
   map<int,int> mp;
   for(auto it:a)mp[it]++;
   set<int> st;
   for(auto it:a)st.insert(it);
   vector<int> tmp;
   for(auto it:st)tmp.push_back(it);
   int j=0;
   int ans=0;
//    for(auto it:tmp)
//    {
//        cout<<it<<" "<<mp[it]<<"\n";
//    }
   //cout<<"****************************\n";
   int exa=0,exb=0;
   for(int i=0;i<tmp.size();i++)
   {
       int val = mp[tmp[i]]-1;
       if(val&1)exa++;
   } 
   if(exa&1)
   {
       ans=tmp.size()-1;
   }
   else
   {
       ans=tmp.size();
   }
   cout<<ans<<"\n";  
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _=1;
    //cin>>_;
    for(int __=0;__<_;__++)
    {
        Digvijay();
    }
}