#include <iostream>

typedef long long ll;

int main(){
   ll n;
   std::cin >> n;
   ll a;
   ll sum[n];
   for(ll i=0; i<n; ++i){
      std::cin >> a;
      if(i==0) sum[i] = a;
      else sum[i] = sum[i-1] + a;
   }

   ll count_plus = 0;
   ll count_minus = 0;
   bool plus = true;
   ll diff_plus = 0;
   ll diff_minus = 0;
   for(ll i=0; i<n; ++i){
      if(plus){
	 if(sum[i]+diff_plus<=0){
	    ll add = -(sum[i] + diff_plus) + 1;
	    count_plus += add;
	    diff_plus += add;
	 }
	 if(sum[i]+diff_minus>=0){
	    ll add = sum[i] + diff_minus + 1;
	    count_minus += add;
	    diff_minus -= add;
	 }
      }else{
	 if(sum[i]+diff_plus>=0){
	    ll add = sum[i] + diff_plus + 1;
	    count_plus += add;
	    diff_plus -= add;
	 }
	 if(sum[i]+diff_minus<=0){
	    ll add = -(sum[i] + diff_minus) + 1;
	    count_minus += add;
	    diff_minus += add;
	 }
      }
      plus = !plus;
   }

   ll ans = std::min(count_plus, count_minus);
   std::cout << ans << std::endl;
   return 0;
}
