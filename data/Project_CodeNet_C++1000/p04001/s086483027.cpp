#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t N;
  cin >> N;
  vector<int> n(0);
  for(;N>0;N/=10)
    n.push_back(N%10);
  reverse(n.begin(),n.end());
  int64_t m=0;
  for(int64_t tmp=0;tmp<(1<<n.size()-1);tmp++){
    bitset<9> s(tmp);
    int64_t j=0,k=n.at(0);
    for(int i=0;i<n.size()-1;i++){
      if(s.test(i)){
        j+=k;
        k=0;
      }else
        k*=10;
      k+=n.at(i+1);
    }
    m+=j+k;
  }
  cout << m << endl;
}