#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <math.h>
#include <utility>
#include <vector>
#include <map>
#include <unordered_map>
#include <cstdlib>
#define div1 1000000007
const long long INF = 1LL << 60;
using namespace std;
using ll = long long;
// a>b -> a==b;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// a<b -> a==b;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

template <class T> void swap(T& a, T& b) { T t = std::move(a); a = std::move(b); b = std::move(t); }

int main(void)
{
    string s, s2, t;
    ll i, j, min=INF, judge, sum, ans=INF;

    cin >> s;

    s2 = s;

    if(s.size()>=2){
        judge = 1;
        for(i=1; i<s.size(); i++){
            if(s[i] != s[0]){
                judge = 0;
            }
        }
    }

    if(s.size()==1){
        cout << 0 << endl;
    }

    else if(judge == 1){ // 全て同じ
        cout << 0 << endl;
    }

    else{
        for(i=0; i<26; i++){ // アルファベット
            sum = 0;
            s = s2;
            judge = 0;
            while(judge == 0){
                sum++;
                t = "";
                judge = 1;

                for(j=0; j<s.size()-1; j++){
                    if(s[j]=='a'+i || s[j+1]=='a'+i){
                        t.push_back('a'+i);
                    }
                    else{
                        t.push_back(s[j]);
                        judge = 0;
                    }
                }

                s = t;

                if(judge==1){
                    break;
                }
            }

            chmin(ans, sum);
        }

        cout << ans << endl;
    }

    return 0;
}