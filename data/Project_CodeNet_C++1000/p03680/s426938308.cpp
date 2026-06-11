#include <bits/stdc++.h>
using namespace std;

int main() {
   int N;
   cin >> N;
   vector<int> light(N);
   for(int i = 0; i < N; i++){
     cin >>light.at(i);
   }
   int NEXT = 1;
   int count = 0;
   int check = 0;
   for(int i = 0; i < N ; i++){
      count++;
      if(light.at(NEXT - 1) == 2){
         check = 1;
         break;
      }else{
         NEXT = light.at(NEXT - 1);
      }
   }
   if(check == 0){
     cout << -1;
   }else{
     cout << count;
   }
}
