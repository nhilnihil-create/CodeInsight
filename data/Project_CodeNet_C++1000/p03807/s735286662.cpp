#include <bits/stdc++.h>
#define P pair<int, int>

using namespace std;
int main(){
  long long n, a[100009];
  cin >> n;
  for(int i=0;i<n;i++)cin >> a[i];
  long long odd=0, even=0;
  for(int i=0;i<n;i++){
    if(a[i]%2==1)odd++;
  }
  cout << (odd%2==0?"YES":"NO") << endl;
}

