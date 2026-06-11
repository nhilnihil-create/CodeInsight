#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
   int n, k, sum = 0;

   cin >> n >> k;
   vector<int> ve(n);

   for(int i = 0; i < n; i++) cin >> ve.at(i); 
   sort(ve.begin(), ve.end());
   for(int i = n - 1; i > n - 1 - k; i--) sum += ve.at(i);

   cout << sum << endl;
}