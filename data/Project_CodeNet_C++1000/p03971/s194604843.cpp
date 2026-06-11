#include <bits/stdc++.h>
using namespace std;
#define rep(i, seisu) for(int i = 0; i < (int)(seisu); i++)

typedef long long ll;

int main(){
 int n, a, b, abroad, yosen;
 cin >> n >> a >> b;
 abroad = 0, yosen = 0;
 string s;
 cin >> s;
 rep(i, n){
   if(s.at(i) == 'a'){
     if (yosen < a+b){
       cout << "Yes" << endl;
       yosen++;
     }
     else {
       cout << "No" << endl;
     }
   }
   else if(s.at(i) == 'b'){
     abroad++;
     if (yosen < a+b && abroad<=b){
       cout << "Yes" << endl;
       yosen++;
     }
     else{
       cout <<"No" << endl;
     }
   }
   else {
     cout << "No" << endl;
   }
 }
}
