#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<tuple>
#include<map>
#include<bitset>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n;
  cin >> n;
  vi vec(n);
  for (int i=0; i<n; i++){
    cin >> vec.at(i);
  }

  int min = 4000000;
  for (int i=-100; i<=100; i++){
    int sum=0;
    for (int j=0; j<n; j++){
      sum += (i - vec.at(j)) * (i - vec.at(j));
    }
    if (sum<min){
      min = sum;
    }
  }

  cout << min << endl;
}
