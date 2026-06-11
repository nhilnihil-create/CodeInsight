#include <bits/stdc++.h>
#define int long long
using namespace std;
//string sort (s.begin(),s.end());

main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


       int n;
       cin>>n;

       map<int,int>mp;

       for(int i=0;i<n;i++)
       {
           int x;

          cin>>x;
          mp[x]++;
       }
       int a[n+10];
       int k=0;
       int b[n+10];
       int l=0;
         map<int, int>::iterator itr;
          for (itr = mp.begin(); itr != mp.end(); ++itr) {

             if(itr->second>=2)
             {
                 a[k++]=itr->first;
             }
             if(itr->second>=4)
             {
                 b[l++]=itr->first;
             }
          }
          sort(a,a+k);
          if(l==0)
          {
                if(k<2)
          {
              cout<<0<<endl;
          }
          else
          {
              cout<<a[k-1]*a[k-2]<<endl;
          }

          }
          else
          {
           if(k<2)
          {
              cout<<b[l-1]*b[l-1]<<endl;
          }
          else
          {
              cout<<max((b[l-1]*b[l-1]),(a[k-1]*a[k-2]))<<endl;

          }
          }





}

