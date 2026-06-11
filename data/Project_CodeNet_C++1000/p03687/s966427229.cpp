#include <iostream>
#include <cstring>
using namespace std;

bool allLettersAreEqual(string s) {
      for(int i=0; i<s.size(); i++) {
            if(s[i] != s[0]) return false;
      }
      return true;
}

int bruteForce(int N, string str) {
      int res = 1e9;             // max for integer
      for(int i=0; i<N; i++) {      // try out each letter in the string
            char target = str[i];
            string str2 = str;
            int count = 0;


            while(!allLettersAreEqual(str2)) {
                  string str3 = "";
                  for(int i=0; i<str2.size()-1; i++) {
                        if(str2[i] == target || str2[i+1] == target) {
                              str3 += target;
                        }
                        else str3 += str2[i];
                  }
                  str2 = str3;
                  count++;
            }
            res = min(res, count);
      }
            
      return res;
}

int main() {
      string str;
      cin >> str;
      int N = str.length();

      cout << bruteForce(N, str) << endl;
}