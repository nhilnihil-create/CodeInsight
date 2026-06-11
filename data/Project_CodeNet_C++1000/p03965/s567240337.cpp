#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    string s; cin >> s;
    int p = 0;
    int g = 0;
    int win = 0;
    int lose = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'p'){
            if(p + 1 <= g){
                p++;
            }else{
                g++;
                lose++;
            }
        }else{
            if(p + 1 <= g){
                p++;
                win++;
            }else{
                g++;
            }
        }
    }
    cout << win - lose << endl;
}