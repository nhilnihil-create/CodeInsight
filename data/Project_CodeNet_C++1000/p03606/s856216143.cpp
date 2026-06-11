#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N ;
  int li;
  int ri;
  int result;
  result = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> li;
        cin >> ri;
        result = result + (ri-li) + 1;
    }
    cout << result << endl;
  
  // ここにプログラムを追記

}