//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>

int main(){
    string w;
    cin >> w;
    map<char,int> ma;
    rep(i,0,w.size()){
        ma[w[i]]++;
    }

    bool flg = true;
    for(auto x : ma){
        if(x.second%2!=0) flg = false;
    }
    cout << (flg ? "Yes" : "No") << endl;
    return 0;
}