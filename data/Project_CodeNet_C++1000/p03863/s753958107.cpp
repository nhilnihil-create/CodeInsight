#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a) (a).begin(),(a).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    string s; cin >> s;
    int n = s.size();
    if(s[0] == s[n-1]){
        if(n%2) cout << "Second" << endl;
        else cout << "First" << endl; 
    }else{
        if(n%2) cout << "First" << endl;
        else cout << "Second" << endl;
    }
}