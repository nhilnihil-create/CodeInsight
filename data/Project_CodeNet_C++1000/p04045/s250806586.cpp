#include <iostream>
#include <string>
using namespace std;

int dislike[10];

bool check(int n) {
    while(n) {
        int curr = n % 10;
        if(dislike[curr] == 1) return false;
        n /= 10;
    }
    return true;
}

int main()
{
  int n, k;
  cin >> n >> k;
  for(int i = 0; i < k; i++) {
    int x;
    cin >> x;
    dislike[x] = 1;
  }
  
  for(int i = n; ; i++) {
      if(check(i)) {
          return cout << i , 0;
      }
  }
  
}
