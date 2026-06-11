#include<iostream>
#include<stdio.h>
//#include <bits/stdc++.h>
#include<vector>
#include<float.h>
#include<iomanip>
#include<algorithm>
#include<string>
#include<cstring>
#include<math.h>
#include<cmath>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include <cassert>
#include <cmath>
#include<cstdint>

#define INF 1e9
#define rep(i,n)for(int i=0;(i)<(int)(n);i++)
#define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
#define vec(type,n) vector<type>(n)
#define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))
#define ALL(a)  (a).begin(),(a).end()


using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;



int main(){
    int n;
    string s;
    cin >> n >> s;
    int cnt_L = 0, cnt_R = 0;

    rep(i, n){      //( Lを数える
        if(s[i] == '(')cnt_L++;
        else if(cnt_L > 0)cnt_L--;
    }

    string t = s;
    reverse(ALL(t));

    rep(i, n){      //( Lを数える
        if(t[i] == ')')cnt_R++;
        else if(cnt_R > 0)cnt_R--;
    }
    deque<char> deq;

    rep(i, n)deq.push_back(s[i]);

    rep(i, cnt_L)deq.push_back(')');
    rep(i, cnt_R)deq.push_front('(');

    while(!deq.empty()){
        cout << deq.front();
        deq.pop_front();
    }
}

