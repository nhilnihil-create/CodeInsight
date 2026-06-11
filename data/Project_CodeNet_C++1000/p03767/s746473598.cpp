 #include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> a(3*N);
  for(int i = 0; i < 3*N; i++) cin >> a[i];
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  
  int64_t sum = 0;
  int count = N;
  for(int i = 1; i<3*N-1; i+=2){
    
    sum += a[i];
    
    count--;
    if(count==0)break;
    
  }
  cout << sum << endl;
}
