#include <bits/stdc++.h>
using namespace std;

long long calc(string S){
  long long sum=0;
//cout << "S=" << S << endl;
  sum += stoll(S);
  
  for (int i=1; i<S.size(); i++){
    string Sl = S.substr(0,i);
    string Sr = S.substr(i);
//cout << "Sl=" << Sl << endl;
//cout << "Sr=" << Sr << endl;
    
    sum += stoll(Sl) * pow(2,floor(log10(stoll(Sr))));
    sum += calc(Sr);
//cout << "floor(log10(atoi(Sr.c_str()))=" << floor(log10(atoi(Sr.c_str()))) << endl;
  }
//cout << "S=" << S << "; sum=" << sum << endl;
  return sum;

  /*
  if(S.size() == 2){
    sum += calc(S.substr(0,1));
    sum += calc(S.substr(1,1));
  }else if(S.size() > 2){
    sum += calc(S.substr(0,1));
    sum += calc(S.substr(1));
    sum += calc(S.substr(1,1));
    sum += calc(S.substr(0,S.size()-1));   
  }
  return sum;
  */
}

int main(){
  string S;
  cin >> S;
//cout << S.size();
  long long sum;
  sum = calc(S);
  
  cout << sum;
}