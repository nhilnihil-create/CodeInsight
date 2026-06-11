#include <bits/stdc++.h>
 
using namespace std;
inline void prep ()
{
  cin.tie (0);
  cin.sync_with_stdio (0);
};
const double pi = acos(-1.);
//printf(%.12lf\n,mid);
// __builtin_popcount(int) count 1's in binary
// get decimal part of number
/*
double intpart;
double thiss = modf((double)(n*m)/(double)k, &intpart);
*/
// round = (int)(num+.5)
long long mod = 1000000007;

// 32 mil = ~1 sec 
long long mymod(long long num){
  if (num< 0 && !(num%mod == 0)){
    if (mod == 1){
      return 0;
    }
    return mod-abs(num)%mod;
  }else{
    return num%mod;
  }
}
 
/*string sentence = And I feel fine...;
    istringstream iss(sentence);
*/  
 
double eps = .000000001;

int BIT[100001], sizee = 100001;
void update(int x, int delta)
{   
     for(; x <= sizee; x += x&-x){
       //cout << (x&-x) << endl;
       BIT[x] += delta;
     }
}
int query(int x)
{
    int sum = 0;
    for(; x > 0; x -= x&-x){
       sum += BIT[x];
       //cout << x << " " << BIT[x] << endl;
    }
    return sum;
}
int main ()
{
  prep();
  long long n, m;
  cin >> n >> m;
  vector<pair<int, pair<int, int> > > pairs;

  for (int i=0; i<n; i++){
      int a, b;
      cin >> a >> b;
      pairs.emplace_back(b-a+1, make_pair(a, b));
  }
  
  sort(pairs.begin(), pairs.end());
  // sums will represent all under x, since all over or == to x must have it
  int curind = 0;
  for (int i=1; i<=m; i++){
      while (curind < pairs.size() && pairs[curind].first < i){
          
          // add to sum
          update(pairs[curind].second.first, 1);
          update(pairs[curind].second.second+1, -1);
          curind++;
      }
      int summ = 0;
      for (int j=i; j<=m; j += i){
          summ += query(j);
          
      }
      cout << summ+n-curind << '\n';
      //cout << summ << " " << curind << endl;
  }
  
  return 0; 
}
