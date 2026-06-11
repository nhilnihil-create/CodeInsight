#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    string s;
    cin>>s;
    int len = (int)s.size();
    cout <<s[0]<<len-2<<s[len-1]<< endl;
    return 0;
}