#include<iostream>

using namespace std;

int main(){
   int n, a, count = 0, ocount = 0;
   int colar[8] = {};

   cin >> n;
   for(int i = 0; i < n; i++){
      cin >> a;
      if(a < 3200){
         colar[a/400]++;
      }else{
         ocount++;
      }
   }

   for(int i = 0; i < 8; i++) if(colar[i] != 0) count++;
   cout << (count != 0 ? count : 1) << " " << count + ocount << endl;
}