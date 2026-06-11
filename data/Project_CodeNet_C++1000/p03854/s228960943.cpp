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

int main() {

  string s;
  cin >> s;

  
  string dream = "dream";
  string dreamer = "dreamer";
  string erase = "erase";
  string eraser = "eraser";

  reverse(s.begin(), s.end());
  reverse(dream.begin(), dream.end());
  reverse(dreamer.begin(), dreamer.end());
  reverse(erase.begin(), erase.end());
  reverse(eraser.begin(), eraser.end());

  string t = "";
  int next = 0;

  while (1) {
    if (next == s.size()) {
      cout << "YES" << endl;
      return 0;
    }
    int i = s.find(dream, next);
    if (i == next) {
      next += dream.size();
      continue;
    }
    i = s.find(dreamer, next);
    if (i == next) {
      next += dreamer.size();
      continue;
    }
    i = s.find(erase, next);
    if (i == next) {
      next += erase.size();
      continue;
    }
    i = s.find(eraser, next);
    if (i == next) {
      next += eraser.size();
      continue;
    }
    cout << "NO" << endl;
    return 0;
  }
}
