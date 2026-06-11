#include <bits/stdc++.h>
using namespace std;
 
#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
int main(){
  long long N;
  cin >> N;
  vector<long long> a;
  froop1(1,sqrt(N) + 1){
    if(N % i == 0){
      a.push_back(N / i);
    }
  }
  sort(a.begin(),a.end());
  int count = 0,c = a.at(0);
  while(c > 0){
	c /= 10;
    count++;
  }
  cout << count << endl;
}