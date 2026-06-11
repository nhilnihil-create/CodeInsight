#include <bits/stdc++.h>
#define int long long
using namespace std;
//string sort (s.begin(),s.end());

main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


      string s;
      cin>>s;
       map<char,int>mp;

       for(int i=0;i<s.size();i++)
       {




          mp[s[i]]++;
       }

         map<char, int>::iterator itr;
         int k=0;
          for (itr = mp.begin(); itr != mp.end(); ++itr) {
                if((itr->second)&1)
                {
                    k=1;
                    break;
                }


          }
          if(k)
          {
              cout<<"No"<<endl;
          }
          else
          {
              cout<<"Yes"<<endl;
          }


}

