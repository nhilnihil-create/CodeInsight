#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
   int x, a, b;
   cin >> x >> a >> b;
   //xからaとbを引いてaかbの絶対値が小さい方を出力
   int A = abs(x-a);
   int B = abs(x-b);
   if(A<B)cout << "A" <<endl;
   else cout << "B" <<endl;
}