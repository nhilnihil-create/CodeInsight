#include<iostream>
using namespace std;

int main(){
  int n,a,b;
  cin >> n >> a >> b;
  string s;
  cin >> s;
  int sum1=0,sum2=0;
  for(int i=0;i<n;i++){
    if(s[i]=='a'){
      if(sum1<a+b){
        cout << "Yes" << endl;
        sum1++;
      } else{
        cout << "No" << endl;
      }
    }else if(s[i]=='b'){
      if(sum1 <a+b && sum2 <b){
        cout << "Yes" << endl;
        sum1++;
        sum2++;
      }else{
        cout << "No" << endl;
      }
    }else if(s[i]=='c'){
      cout << "No" << endl;
    }
  }
}

/*
10 2 3
abccabaabb

Yes
Yes
No
No
Yes
Yes
Yes
No
No
No
*/