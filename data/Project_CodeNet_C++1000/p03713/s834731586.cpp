#include <iostream>

int main(){
   long long H, W;
   std::cin >> H >> W;

   long long ans = H*W;
   for(long long i=1; i<H; ++i){
      long long S0 = W * i;
      long long S1 = W/2 * (H-i);
      long long S2 = (W-W/2) * (H-i);
      long long max = std::max(S0,std::max(S1,S2));
      long long min = std::min(S0,std::min(S1,S2));
      ans = std::min(ans,max-min);

      S1 = W * ((H-i)/2);
      S2 = W * (H-i-(H-i)/2);
      max = std::max(S0,std::max(S1,S2));
      min = std::min(S0,std::min(S1,S2));
      ans = std::min(ans,max-min);
   }
   for(long long i=1; i<W; ++i){
      long long S0 = H * i;
      long long S1 = H/2 * (W-i);
      long long S2 = (H-H/2) * (W-i);
      long long max = std::max(S0,std::max(S1,S2));
      long long min = std::min(S0,std::min(S1,S2));
      ans = std::min(ans,max-min);

      S1 = H * ((W-i)/2);
      S2 = H * (W-i-(W-i)/2);
      max = std::max(S0,std::max(S1,S2));
      min = std::min(S0,std::min(S1,S2));
      ans = std::min(ans,max-min);
   }
   std::cout << ans << std::endl;
   return 0;
}
