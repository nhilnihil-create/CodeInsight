#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i,s,n) for(int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(){
   int n;
   cin >> n;
   bool a[9] = {};
   int count3200 = 0;
   rep(i, n) {
       int rate;
       cin >> rate;
       rate = rate / 400;
       if(rate == 0)
           a[rate] = true;
       else if(rate == 1)
           a[rate] = true;
       else if(rate == 2)
           a[rate] = true;
       else if(rate == 3)
           a[rate] = true;
       else if(rate == 4)
           a[rate] = true;
       else if(rate == 5)
           a[rate] = true;
       else if(rate == 6)
           a[rate] = true;
       else if(rate == 7)
           a[rate] = true;
        else{
            rate = 8;
            a[rate] = true;
            count3200++;
        }
   }

   int count = 0;
   rep(i,8){
       if(a[i])
           count++;
   }
   int min_color = count;
   if(min_color == 0)
       min_color = 1;
   int max_color = count + count3200;
   cout << min_color << " " << max_color << endl;
   return 0;
}