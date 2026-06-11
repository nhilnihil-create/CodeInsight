#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
vector<int> i;
vector<int> u;
int o[11000000];
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  long long a=0,b,c,d=0,e=0,f=0,g;
  string s;
   cin >>a;
   for(int n=1;n<=a;n++){
     d+=n;
     o[n]=1;
     if(d>a){
       o[d-a]=0;
       break;
     }
     if(d==a) break;
   }
   for(int n=1;n<=a;n++){
     if(o[n]==1) cout <<n<<'\n';
   }
   return (0);
}
