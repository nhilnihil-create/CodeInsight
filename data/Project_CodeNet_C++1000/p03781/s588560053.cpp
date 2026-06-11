#include <functional>
#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include <numeric>
using ll = long long;
using namespace std;
# define maxn 50
# define maxm 50

int main() {
  int x;
  cin>>x;
  for (int i(0);i*i/3<x;i++){
    if(i*(i+1)/2>=x){
      cout<<i;
      return 0;
    }
  }
}
