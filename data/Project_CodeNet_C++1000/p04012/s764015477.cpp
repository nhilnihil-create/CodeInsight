#include<iostream>
using namespace std;
 
int isBeautiful(string str){
  int arr[26] = {0};
  for (int i = 0; i < str.length(); i ++){
    arr[str[i] - 'a'] ++;
  }
  for (int i = 0; i < 26; i ++){
    if (arr[i] % 2 != 0){
      return false;
    }
  }
  return true;
}
int main (){
  string str;
  cin >> str;
  if (isBeautiful(str)){
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}