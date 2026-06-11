 #include <bits/stdc++.h>
using namespace std;

int main() {
  string s; cin >> s;
  string alfa = "abcdefghijklmnopqrstuvwxyz";
   vector<int> num(26);
  int size = s.size();
  for(int i = 0; i<size;i++){
    for(int j = 0; j<26;j++){
      if(s.at(i)== alfa.at(j)){
        num[j] = 1;
      }
    }
  }
    char ans = 'a';
  int count = 0;
    for(int i = 0; i < 26; i++){
      if(num[i]==0){
       printf("%c", ans+i);
        break;
      } else count++;
    }
  if(count==26) cout << "None" << endl;
}
