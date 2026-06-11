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
    string s;
    ll k;
    cin >> s >> k;
    vector<int>diff(s.length());
    REP(i,s.length()){
        diff[i] = ('z'+1-s[i])%26;
    }
    REP(i,s.length()){
        if(diff[i] <= k){
            s[i] = 'a';
            k-=diff[i];
        }
    }
    if(k>0){
        k = k%26;
        s[s.length()-1]+=k;
        //if(s[s.length()-1]>'z')s[s.length()-1]-=26;
    }
    cout << s << endl;
    return 0;
}