#include <bits/stdc++.h>
using namespace std;
 int main(){
      int n;
      cin >> n;
      vector<int> s(n);
      int ans=0;
      for(int i=0;i<n;i++){
          cin >> s.at(i);
        ans+=s.at(i);
      }
      sort(s.begin(),s.end());
      for(int i=0;i<n;i++){
        
        if(ans%10!=0){
          cout << ans << endl;
       break;
        }
        if(s.at(i)%10!=0){
        ans-=s.at(i);
        cout << ans << endl;
        break;
        }
        
      }
      if(ans%10==0){
          cout << 0 << endl;
      }

      return 0;
 }