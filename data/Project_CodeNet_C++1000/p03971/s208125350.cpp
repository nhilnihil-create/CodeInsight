#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793
 
   
int main(){
   int n,a,b;
   cin  >> n >> a >> b;
   string s;
   cin >> s;
   int x=0;
   int y=0;
   int m=s.size();
   rep(i,m){
       if(s.at(i)=='a'){
           if(x<(a+b)){
               x++;
               cout << "Yes" << endl;
           }
           else cout << "No" << endl;
       }
       else if(s.at(i)=='b'){
           if(x<(a+b) && y<b){
               x++;
               y++;
               cout << "Yes" << endl;
           }
           else cout <<  "No" << endl;
       }
       else if(s.at(i)=='c')cout << "No" << endl;
   }

} 