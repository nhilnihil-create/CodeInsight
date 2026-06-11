#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

int freq[26];
int hasil[26];
int indx[26];
int main() {
  string m;
  cin >> m;
  
  memset(freq, 0, sizeof(freq));
  int maxfreq = 0;
  for (int i = 0; i < m.length(); i++){
    char f = m[i];
    freq[f-'a'+1]++;
    if (freq[f-'a'+1] > maxfreq){
      maxfreq = freq[f-'a'+1];
    }
  }
  
  int h = INT_MAX;
  for (int a = 1; a <= 26; a++){
    int distmax = 0;
    int f = a;
    string temp = m;

    temp = (char)(f-1+'a') + temp + (char)(f-1+'a');
    int dist = 0;
    for (int i = 0; i < temp.length(); i++){
      dist++;
      int n = temp[i] - 'a' + 1;
      if(n == f){
        distmax = max(distmax, dist-1);
        dist = 0;
      }
    }

    h = min(h, distmax);
  }

  cout << h << endl;
  return 0;
}