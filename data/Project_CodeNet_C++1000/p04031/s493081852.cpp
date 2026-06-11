#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
 
unsigned int getCost(int changeNum, vector<int> &a){
  unsigned int cost = 0;
  const size_t aSize = a.size();
  for(int i = 0; i < aSize; i++){
    cost += pow(a[i] - changeNum, 2.0);
  }
  return cost;
}
 
unsigned int getResult(vector<int> &a){
  unsigned int minCost = 1e9;
  for(int i = -100; i <= 100; i++){
    unsigned int cost = getCost(i, a);
    minCost = min(cost, minCost);
  }
  return minCost;
}
 
int main(){
  int N;
  cin >> N;
  vector<int> a;
  for(int i = 0; i < N; i++){
    int ai;
    cin >> ai;
    a.push_back(ai);
  }
  unsigned int result = getResult(a);
  cout << result << endl;
}