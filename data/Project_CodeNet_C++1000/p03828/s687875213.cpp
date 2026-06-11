#include <bits/stdc++.h>
#include <math.h>
using namespace std;
bool is_prime(int x){
    bool f = true;
    if(x == 2){ f = true; }
    else if(x < 2 || x % 2 == 0){ f = false; }
    else{
        int i = 3;
        while(i <= sqrt(x)){
            if(x % i == 0){ f = false; break;}
            i += 2;
        }
    }
  return f;
}

int main(){
  int n;
  cin >> n;
  vector<int> v(0);
  for(int i = 1; i <= n; i++){
    if(is_prime(i)){v.push_back(i);}
  }
  
  vector<int> w(v.size(), 0);
  for(int i = 0; i < v.size(); i++){
    if(w[i] > pow(n, 0.5)){
    w[i] = n / v[i];
    }
    else{
      int j = 1;
      while(pow(v[i], j) <= n){
        w[i] += (n / pow(v[i], j));
        j++;
      }
    }
  }
  
  long long ans = 1;
  long long q = pow(10, 9) + 7;
  
  for(int i = 0; i < w.size(); i++){
    ans *= w[i] + 1;
    ans %= q;
  }
	//for(auto c : w){cout << c << endl;}
  cout << ans << endl;
  
}
       