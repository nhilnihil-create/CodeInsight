#include <bits/stdc++.h>
using namespace std;

int convert_num(char x){
  vector <char> data = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  auto it = find(data.begin(),data.end(),x);
  auto index = distance(data.begin(),it);
  return index;
}

char convert_ar(int x){
  vector <char> data = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  return data[x];
}
  

int main(){
  string S;
  cin >> S;
  vector<int> num(26,0);
  char ans;
  for(int i=0;i<S.size();i++){
    int a = convert_num(S.at(i));
    num[a]++;
  }
  bool op = false;
  for(int i=0;i<26;i++){
    if(num[i] == 0){
      ans = convert_ar(i);
      op = true;
      break;
    }
  }
  if(op==0){
    cout << "None" << endl;
  }
  else{
  cout << ans << endl;
  }
}