#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#define REP(i,a) for (int i = 0;i < (a);++i)
#define FOR(i,a,b) for (int i = (a);i < (b); ++i)
#define FORR(i,a,b) for (int i = (a);i >= (b); --i)
#define ALL(obj) (obj).begin(),(obj).end()
#define SORT(list) sort(ALL((list)));
#define MOD 1000000007
using namespace std;
using ll = long long;
int main(){
    vector<string>s(2);
    int n;
    cin >> n;
    cin >> s[0] >> s[1];
    ll answer = 1;
    string tate="tate",yoko="yoko";
    string prev;
    REP(i,n){
        if(s[0][i]==s[1][i]){
            if(prev == tate){
                answer=answer*2%MOD;
            }else if(prev == yoko){
                //answer=answer*1%MOD;
            }else{
                answer=answer*3%MOD;
            }
            prev = tate;
        }else{
            if(prev == tate){
                answer=answer*2%MOD;
            }else if(prev == yoko){
                answer=answer*3%MOD;
            }else{
                answer=answer*6%MOD;
            }
            i++;
            prev = yoko;
        }
    }
    cout<< answer << endl;
    return 0;
}