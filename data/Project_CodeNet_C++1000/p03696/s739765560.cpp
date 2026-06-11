#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define _GLIBCXX_DEBUG
#define rep(i, V) for (int i = 0; i < V; i++)
#define repr(i, V) for (int i = V-1; i >= 0; i--)
#define repval(i, a, V) for (int i = a; i < V ; i++)
#define all(x) x.begin(), x.end()
#define ld long double
#define eps 0.0000000001
#define mod 1000000007
#define inf 1e16
#define vec vector
#define each(i, mp) for(auto& i:mp)

int main(){
    int n;
    string s;
    cin >> n;
  	cin >> s;

    int l = 0;
    int ansl = 0;
  	int ansr = 0;    
    rep(i, (int)s.size()){
        if (s[i] == '('){
            l++;
        }else if(l > 0){
            l--;
        }else{
            ansl++;
        }
    }
    ansr = l;
  
 	rep(i, ansl) cout << '('; cout << s; rep(i, ansr) cout << ')';
}