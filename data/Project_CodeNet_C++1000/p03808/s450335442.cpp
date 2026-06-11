# include <bits/stdc++.h>
using namespace std;

/*
  idea : find difference between each adjacent boxes :
  d[i] = a[i+1] - a[i]

  for each "taking", each d[i] is decreased by 1 
  (for example if the box consists 3 balls and 2 balls at beginning, this d[i] = -1
  taking 1 balls at 3 makes it become 2
  taking 2 balls at 2 makes it become 0
  now d[i] becomes -2)

  but for the last box in the taking, the d[i] is no longer decreased by 1, rather it's increased by (n-1) 
  because it's a circular.
  (for example there are 5 total boxes 
  the last box at first has 7 balls and the first box at first has 10 balls. d[i] = 3 at first
  taking 5 balls at 7 makes it become 2
  taking 1 balls at 10 makes it become 9
  now d[i] = 7)
  
  ----------------------

  first, add all balls in total (call it S). In each taking, we take n*(n+1)/2 balls
  therefore, S has to be a multiple of n*(n+1)/2 to be possible

  now assume the number of operation K is S / (n*(n+1)/2), now :
  for each i :
  so for each d[i], we find :
  - how many times it is increased by (n-1)       --> call it x
  - how many times it is decreased by 1           --> call it (K-x)

  therefore : 
  d[i] + x*(n-1) - 1*(K-x) = 0      --> because in the end, to be possible, difference between two adjacent box must be 0
  so :
  d[i] + xn - x - K + x = 0
  d[i] + xn - K = 0
  xn = K - d[i]
  x = (K - d[i]) / n
  
  thus :
  for each i :
    --> K - d[i] must be >= 0
    --> K - d[i] must be multiples of n
  to be POSSIBLE
*/

# define ll long long
int main(){

  ll n, ball[100005];
  cin >> n;
  ll S = 0;
  for(int i=0; i<n; i++){
    cin >> ball[i];
    S += ball[i];
  }

  if(S % (n*(n+1)/2) != 0){
    cout << "NO" << endl;
    return 0;
  }

  ll K = S / (n*(n+1)/2);
  for(int i=0; i<n; i++){
    ll di = (ball[(i+1)%n] - ball[i]);
    if(K - di < 0 || (K - di)%n != 0){
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;
  return 0;
}