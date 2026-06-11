// バケット法による解
#include <iostream>
using namespace std;

int main() {
    string S;
    cin >> S;
    bool app[30];
    bool flug = false;
    for(int i = 0; i< 26;++i){
      app[i] = false;
    }
    for(int i = 0;S[i] != '\0';++i){
      app[S[i]-'a']= true;
    }
    for(int i = 0;i<26;++i){
      if(!app[i]){
        cout << (char)(i + 'a') << endl;
        flug = true;
        break;
      }
    }
    if(!flug) {
        cout << "None" << endl;
    }
}
