#include <iostream>

int main(){
   const int mod = 1000000007;
   int N;
   std::cin >> N;
   std::string S[2];
   std::cin >> S[0] >> S[1];

   long long ans = 3;
   if(N>1 && S[0][0]!=S[1][0]) ans *= 2;
   for(int i=1; i<N; ++i){
      if(S[0][i]==S[1][i]){
	 if(S[0][i-1]==S[1][i-1]) ans *= 2;
      }else if(S[0][i-1]!=S[0][i]){
	 if(S[0][i-1]==S[1][i-1]) ans *= 2;
	 else ans *= 3;
      }
   }
   std::cout << ans%mod << std::endl;

   return 0;
}
