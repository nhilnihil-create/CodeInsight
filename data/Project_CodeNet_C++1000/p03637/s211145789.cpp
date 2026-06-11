#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool check(string s){
  int n = s.length();
  if (n%2==1){
    return false;
  }
  else {
    return (s.substr(0,n/2-1)==s.substr(n/2));
  }
}

int main(){
  int n;
  cin >> n;

  int a[n];
  int b[n];

  int cnt1=0, cnt2=0, cnt4=0;
  for (int i=0; i<n; i++){
    cin >> a[i];
    if (a[i]%4==0){
      b[i] = 4;
      cnt4++;
    }
    else if (a[i]%2==0){
      b[i] = 2;
      cnt2++;
    }
    else {
      b[i] = 1;
      cnt1++;
    }
  }

  if (cnt1<=cnt4+1 && cnt2==0){
    cout << "Yes" << endl;
    return 0;
  }
  else if (cnt1<=cnt4){
    cout << "Yes" << endl;
    return 0;
  }

  cout << "No" <<endl;
  return 0;
}
