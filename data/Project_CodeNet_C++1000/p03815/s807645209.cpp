    #include <bits/stdc++.h>
    using namespace std;
    int main(){
      long long n;
      cin >> n;
      long long  ans = (n/11)*2;
      if(n%11  > 0){
      	if(n%11 > 6)ans +=2;
      	else ans++;
      }
      cout<<ans<<"\n";
      return 0;
    }