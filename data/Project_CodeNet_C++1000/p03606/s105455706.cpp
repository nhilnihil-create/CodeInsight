#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, i, count = 0, start, end;
  cin >> N;
  
 for ( i = 0; i < N; i++) { 
   cin >> start >> end ;
	count += end - start + 1;
 }
  cout << count << endl;
}