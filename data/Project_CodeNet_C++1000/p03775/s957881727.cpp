#include <bits/stdc++.h>
using namespace std;

int main(){
 long long N;
 cin >> N;
 set<int> a;
 for(long long i = 1; i * i <= N; i++){
   if(N % i == 0){
     long long digit, digit2;
     digit = (int)log10(i);
     digit2 = (int)log10(N / i);
     a.insert(max(digit, digit2) + 1);
   }
 }
 cout << *begin(a) << endl;
}
