#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793

int main(){
  string a,b,c;
  cin >> a >> b >> c;
  int na=a.size();
  int nb=b.size();
  int nc=c.size();
  int aa=0;
  int bb=0;
  int cc=0;
  char x='a';
  char ans;
  rep(i,na+nb+nc){
    if(aa==na && x=='a'){
      ans='A';
      break;
    }
    else if(bb==nb && x=='b'){
      ans='B';
      break;
    }
    else if(cc==nc && x=='c'){
      ans='C';
      break;
    }
    else if(x=='a'){
      x=a.at(aa);
      aa++;
      
    }
    else if(x=='b'){
      x=b.at(bb);
      bb++;
      
    }
    else if(x=='c'){
      x=c.at(cc);
      cc++;
      
    }
  }
  cout << ans << endl;
}


    
   
