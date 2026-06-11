#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX;
#define INFL LLONG_MAX;
typedef long long ll;
using namespace std;
int main(){

int a,i,N,A=0,B=0,C=0,D=0;
int E=0,F=0,G=0,H=0,X=0,max,min;

cin >> N;

for(i=0;i<N;i++){
  cin >> a;

  if(a>=1 && a<=399){
    X=1;
  }
  else if(a>=400 && a<=799){
    A=1;
  }
  else if(a>=800 && a<=1199){
    B=1;
  }
  else if(a>=1200 && a<=1599){
    C=1;
  }
  else if(a>=1600 && a<=1999){
    D=1;
  }
  else if(a>=2000 && a<=2399){
    E=1;
  }
  else if(a>=2400 && a<=2799){
    F=1;
  }
  else if(a>=2800 && a<=3199){
    G=1;
  }
  else{
    H+=1;
  }
}

max=X+A+B+C+D+E+F+G+H;
min=X+A+B+C+D+E+F+G;

if(min==0){
  min=1;
}

cout << min << " " << max << endl;

}
