#include <iostream>
#include <vector>

int main(){
   int H, W;
   std::cin >> H >> W;
   std::vector<std::vector<char>> C(H, std::vector<char> (W));
   std::vector<std::vector<char>> Cout(2*H, std::vector<char> (W));
   for (int i=0; i<H; i++){
      for (int j=0; j<W; j++){
         std::cin >> C.at(i).at(j);
      }
   }

   for (int i=0; i<2*H; i++){
      for (int j=0; j<W; j++){
         std::cout << C.at(i/2).at(j);
      }
      std::cout << std::endl;
   }

}

