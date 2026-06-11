/*ॐॐ*/
/* I have already deleted My old account because somebody stole my code
and i have no idea how. If you are copying this code atleast make it look different.
Change variable names or change some Data structres or anything just make sure MOSS do not
Detect Anything.
Yours Faithfully
Shobhit Yadav */
/*my variables are anime character */

/* I do not fear this new challenge. Rather like a true warrior I will rise to meet it. 
                                       -Prince Vegeta  */

 /* “Strength is the only thing that matters in this world. Everything else is just a delusion for the weak.” – Vegeta */

#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define vll vector<ll>
#define pll pair<ll , ll> 
#define vpll vector<pll>
#define umpll unordered_map<ll , ll>
#define mpll map<ll , ll>
#define sll set<ll>
#define stll stack<ll>
#define FIO  ios_base::sync_with_stdio(false);  cin.tie(0); cout.tie(0);



ll N,T;
/*ll freq[200005];*/
char pix[100][100];
ll H,W;
void solve(){
   /*memset(freq,0,sizeof(freq));*/
  cin>>H>>W;

  for(ll i = 0 ; i<H ; i++){
    for(ll j = 0 ; j<W ; j++)
      cin>>pix[i][j];
  }

  for(ll i = 0 ; i<H ; i++){
    for(ll k = 0 ; k<2 ; k++){
      for(ll j = 0 ; j<W ; j++){
        cout<<pix[i][j]; 
    }
    cout<<'\n';
    }
  }

}



int main(){
  
  FIO 
  
 solve();

  return 0;
}