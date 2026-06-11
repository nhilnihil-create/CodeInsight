#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // long long64_t, long long*_t
#include <cstdio> // prlong longf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack 
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <math.h>
#include <iomanip> //setprecision
#include <limits>
#include <list>
using namespace std;
int main(){
  int n,m;
  cin >> n >> m;
  vector<int> x(m);
  vector<int> y(m);
  vector<int> a(n,1);//個数
  vector<int> b(n,0);//red++
  b[0]=1;
  for(int i=0; i<m; i++){
    cin >> x[i] >> y[i];
    if(b[x[i]-1]!=0){
      if(a[x[i]-1]==1){
        b[x[i]-1]=0;
        b[y[i]-1]=1;
      }
      else{
        b[y[i]-1]=1;
      }
    }
    a[y[i]-1]++;
    a[x[i]-1]--;
  }
  int sum=0;
  for(int i=0; i<n; i++){
    if(b[i]>0) sum++;
  }
  cout << sum << endl;
}
