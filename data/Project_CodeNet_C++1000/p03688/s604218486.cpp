/// awoooooo

# include <bits/stdc++.h>
# define sz(x) (int)((x).size())

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;

const int N = (int)2e5 + 5;
const int inf = (int)1e9 + 7;

int n;
int a[N];
set < int > s;

int main(){
  cin >> n;
  for(int i = 1; i <= n; ++i){
    cin >> a[i];
    s.insert(a[i]);
  }
  if(sz(s) == 1){
    if(*s.begin() == n - 1 || *s.begin() * 2 <= n){
      cout << "Yes\n";
    } else{
      cout << "No\n";
    }
  } else if(sz(s) == 2){
    int c1 = count_if(a + 1, a + 1 + n, [&](int x){
      return x == *s.begin();
    });
    int c2 = count_if(a + 1, a + 1 + n, [&](int x){
      return x == *s.rbegin();
    });
    if(*s.begin() + 1 != *s.rbegin()){
      cout << "No\n";
      return 0;
    }
    if(!(c1 <= *s.begin() && c1 + c2 / 2 >= *s.rbegin())){
      cout << "No\n";
      return 0;
    }
    cout << "Yes\n";

  } else{
    cout << "No\n";
  }

  return 0;
}
