#include <bits/stdc++.h>
using namespace std;
 
int main() {
      string s;
      cin >>s;
      s.pop_back();
      for(int i=0;i<200;i++){
        int n=s.size();
        if(n%2==1){
            s.pop_back();
            continue;
        }
        string a=s.substr(0,n/2) , b = s.substr(n/2,n/2);
        if(a==b){
            cout<<s.size()<<endl;
            return 0;
        }
        else{
            s.pop_back();
        }
     }   
}