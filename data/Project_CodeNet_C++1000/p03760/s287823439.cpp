#include <iostream>
#include <string>

int main(){
   std::string O, E;
   std::cin >> O >> E;
   std::string S, Sout;
   S = O + E;
   int N = S.size();
   for (int i=0; i<N; i++){
      if (i % 2 == 0){
         Sout = Sout + O.at(i/2);
      } else{
         Sout = Sout + E.at(i/2);
      }
   }
   std::cout << Sout << std::endl;

}

