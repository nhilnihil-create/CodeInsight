#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
using Graph = vector<vector<int>>;

#define INF (1 << 21);

int main(){
  int n, k;cin >> n >> k;
  cout << n * n - k;
}
