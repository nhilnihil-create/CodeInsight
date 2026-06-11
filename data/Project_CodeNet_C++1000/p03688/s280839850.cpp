# include <bits/stdc++.h>
using namespace std;

/*
  Suppose that there are A colors in total.
  We call a cat alone if no other cat wears a hat of the same color as this cat.
  If the cat i is alone, ai = A − 1, and otherwise ai = A. Therefore, the difference
  between the maximum of ai and the minimum of ai must be at most one.

  Case I. max = min
  There are two cases: all cats are alone or all cats are not alone. In the former
  case, ai = N − 1, and in the latter case, 2ai ≤ N. Thus, if one of the above is
  true, the answer is Yes, otherwise the answer is No.

  Case II. max - min = 1
  In this case, A must be the maximum of ai
  . Let x be the number of alone cats
  (the number of A − 1), and let y be the number of non-alone cats. The number
  of colors among alone cats is x, and the number of colors among non-alone cats
  is between 1 and y/2. Thus, if x+ 1 ≤ A ≤ x+y/2, the answer is Yes, otherwise
  the answer is No.
*/

int cnt[100005];
int main(){

  int n;
  cin >> n;
  int mx = 0, mn = 1e9;
  for(int i=0; i<n; i++){
    int cat; cin >> cat;
    mx = max(mx, cat);
    mn = min(mn, cat);
    cnt[cat]++;
  }

  if(mx - mn > 1) {
    cout << "No" << endl;
    return 0;
  }
  else if(mx == mn){
    if(mx == n-1 || 2*mx <= n) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
  }
  else {
    int alone = cnt[mn];
    int notAlone = cnt[mx];
    
    if(alone+1 <= mx && mx <= alone + (notAlone/2)) cout << "Yes" << endl;
    else cout << "No" << endl;
  }

  return 0;
}