#include <iostream>
#include <map>

using namespace std;

int main(){
  long long N;
  map<long long,char> price_for_double;
  long long Q,H,S,D;
  long long sum=0;
  cin >> Q >> H >> S >> D;
  cin >> N;
  price_for_double.insert(make_pair(Q*8,'Q'));
  price_for_double.insert(make_pair(H*4,'H'));
  price_for_double.insert(make_pair(S*2,'S'));
  price_for_double.insert(make_pair(D,'D'));
  
  auto iter = price_for_double.begin();

  if (iter->second=='D'){
    sum = (N/2)*(iter->first);
    iter=next(iter,1);
    if (N%2==1) sum+= iter->first/2;
  }else{
    sum = N*(iter->first/2);
  }
  cout <<sum<<endl;
    
  
}