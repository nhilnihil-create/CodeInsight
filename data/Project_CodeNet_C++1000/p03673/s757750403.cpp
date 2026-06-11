#include<iostream>
#include<list>

using namespace std;

int main(){
   int n, a;

   cin >> n;
   list<int> li;
   list<int>::iterator ite;

   for(int i = 0; i < n; i++){
      cin >> a;
      if(i % 2 == 0){
         li.push_front(a);
      }else{
         li.push_back(a);
      }
   }
   if(n % 2 == 0) li.reverse();

   ite = li.begin();
   while(ite != li.end()){
      cout << *ite << ' ';
      ite++;
   }
}