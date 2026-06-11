#include<iostream>
#include<deque>

using namespace std;

int main(){
   int n, a;

   cin >> n;
   deque<int> li;

   for(int i = 0; i < n; i++){
      cin >> a;
      if(i % 2 == 0){
         li.push_front(a);
      }else{
         li.push_back(a);
      }
   }
   if(n % 2 == 0){
      for(auto i = li.rbegin(); i != li.rend(); i++){
         cout << *i << ' ';
      }
   }else{
      for(auto i = li.begin(); i != li.end(); i++){
         cout << *i << ' ';
      }
   }
}