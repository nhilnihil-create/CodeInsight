//未完
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using ll = long long;
using vec = vector<int>;
using vec2 = vector<vector<int>>;

int main(){
    string s;
    cin >> s;
    vec a(s.size());
    rep(i, s.size()){
        char c = s.at(i);
        int f = c - '0';
        a[i] = f;
    }
    ll sum = 0, m;
        //10は回したいとおりの数、100はビットの数を入れる
    for(int i = 0;i < (1 << (s.size()-1));i++){
        m = a[0];
        for(int j = 0;j < (s.size()-1);j++){
            if(i & (1 << j)){
                sum += m;
                m = 0;
            }

         m = m*10 + a[j+1];

        }
        sum += m;
    }
  cout << sum << endl;
}