#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793

int main(){
   string w;
   cin  >> w ;
   int n=w.size();
   set<char> chk;
   rep(i,n){
       if(chk.count(w.at(i))){
           chk.erase(w.at(i));
       }
       else{
           chk.insert(w.at(i));
       }
   }
   if(chk.size()==0)cout << "Yes" << endl;
   else cout << "No" << endl;
}