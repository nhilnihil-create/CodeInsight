#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX
#define INFL LLONG_MAX
typedef long long ll;
using namespace std;


int main(){
  string sa,sb,sc;
  cin >> sa >> sb >> sc;

  char turn='a';
  ll x=0,y=0,z=0;
  for(ll i=1;i;i++){
    if(sa.size()==x && turn=='a'){
      cout << 'A' << endl;
      return 0;
    }
    else if(sb.size()==y && turn=='b'){
      cout << 'B' << endl;
      return 0;
    }
    else if(sc.size()==z && turn=='c'){
      cout << 'C' << endl;
      return 0;
    }

    if(turn=='a'){
      turn=sa.at(x);
      x++;
    }
    else if(turn=='b'){
      turn=sb.at(y);
      y++;
    }
    else if(turn=='c'){
      turn=sc.at(z);
      z++;
    }



  }

  }
