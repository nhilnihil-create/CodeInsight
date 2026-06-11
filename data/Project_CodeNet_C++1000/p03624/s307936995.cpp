#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793


   
int main(){
   string s;
   cin >>s;
   set<char> chk;
   int n=s.size();
   rep(i,n){
    chk.insert(s.at(i));
   }
   if(chk.size()==26)cout << "None" << endl;
   else{
     rep(i,26)
     if(chk.count(char(i+'a'))){
     }
     else{
       cout << char(i+'a') << endl;
       break;
     }
   }
}