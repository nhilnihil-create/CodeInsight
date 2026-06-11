#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long mod = 1000000007;


int main() {
  string s;
  cin >> s;
  long long n = s.length();
  long long rez = (n*(n-1))/2 + 1;
  vector <long long> bs(26, 0);
  for (int i = 0; i < n; i++)
   bs[s[i] - 'a']++;
  for (int i = 0; i < 26; i++)
   if (bs[i] > 1)
    rez -= (bs[i]*(bs[i]-1))/2;
  cout << rez;
}