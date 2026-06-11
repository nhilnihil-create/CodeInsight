#include <iostream>
#include <vector>
#include <map>

int main(){
   int N;
   std::cin >> N;
   std::map<std::string, int> a;
   for (int i=0; i<N; i++){
      std::string key;
      int temp;
      std::cin >> temp;
      if ((1 <= temp) && (temp <=399))
         key = "grey";
      else if ((400 <= temp) && (temp <=799))
         key = "brown";
      else if ((800 <= temp) && (temp <=1199))
         key = "green";
      else if ((1200 <= temp) && (temp <=1599))
         key = "lite_blue";
      else if ((1600 <= temp) && (temp <=1999))
         key = "blue";
      else if ((2000 <= temp) && (temp <=2399))
         key = "yellow";
      else if ((2400 <= temp) && (temp <=2799))
         key = "orange";
      else if ((2800 <= temp) && (temp <=3199))
         key = "red";
      else
         key = "other";
      a[key]++;
   }
   int cnt = 0;
   for (auto x : a){
      cnt++;
   }
   int nother = a["other"];
   int min = (nother >= 1)? cnt-1 : cnt;
   if (min == 0)
      std::cout << 1 << " " << min+nother << std::endl;
   else
      std::cout << min << " " << min+nother << std::endl;
}

