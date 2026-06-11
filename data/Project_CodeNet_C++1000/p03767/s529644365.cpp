# include <iostream>
# include <map>
# include <algorithm>
using namespace std;

# define ll long long

bool descending(int a, int b){
  return a > b;
}

int main(){
  
  int N;
  cin >> N;
  
  int strength[3*N+5];
  for(int i=0; i<3*N; i++)
    cin >> strength[i];
  sort(strength, strength+3*N, descending);  
  
  ll ans = 0;
  for(int i=1; i<2*N; i+=2)
    ans += strength[i];
  
  cout << ans << endl;
  return 0;
} 