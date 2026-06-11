#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include <sstream>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
#include <iomanip>
#include <numeric>
#include <iterator>
#include <math.h>
#include <list>
#include <bits/stdc++.h>

using namespace std;

int main(void){
  int64_t N,K;
  cin >> N >> K;
  map<long,int64_t> neko;
  for(int i =0; i < N; i++){
    long a,b;
    cin >> a >> b;
    neko[a] += b;
  }

  long sum = 0;
  for(auto it = neko.begin(); it != neko.end(); ++it){
    //cout << it->first <<":"<<sum+1 << "-" << sum + it->second << endl;
    sum += it->second;
    if( K<= sum){
      cout << it->first << endl;
      break;
    }
    

  
  }
  return 0;
}