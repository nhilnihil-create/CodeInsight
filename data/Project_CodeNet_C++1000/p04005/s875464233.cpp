#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(void){
   vector<long long> num(3);
   for (int i = 0; i < 3; i++) cin >> num[i];
   
   for (int i = 0; i < 3; i++){
       if (num[i] % 2 == 0){
           cout << 0 << endl;
           return 0;
       }
   }
   
   sort(num.begin(),num.end());
   cout << num[0] * num[1] << endl;
}
