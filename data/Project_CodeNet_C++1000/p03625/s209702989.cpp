      #include <iostream>
      #include <string>
      #include <vector>
      #include <algorithm>
      #include <utility>
      #include <map>
      using namespace std;
      typedef long long ll;
      #define rep(i, n) for (int i=0;i < (int)(n);i++)

      int main(){
         int n;
         map<ll,int> m;
         cin >> n;
         vector<int> v(n);
         rep(i,n) {
            cin >> v[i];
            m[v[i]]++;
         }
         //sort(v.begin(),v.end());
         ll f = 0LL,s = 0LL;
         for (auto w :m){
            if (w.second >= 4){
               s = w.first;
               f = w.first;
            }
            else if (w.second >= 2) {
               s = f;
               f = w.first;
            }    
         }
         cout << s*f << endl;

         return 0;
         
      }

