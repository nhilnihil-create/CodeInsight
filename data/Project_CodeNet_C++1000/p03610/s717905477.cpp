#include <bits/stdc++.h>
#include <string>
using namespace std;

string s;
int a;


int main(){
    cin>>s;
    a=s.length();
    for(int i=0;i<a;i++){
      if(i%2==0){
        cout << s[i];
      }
    }
    cout<<endl;
}