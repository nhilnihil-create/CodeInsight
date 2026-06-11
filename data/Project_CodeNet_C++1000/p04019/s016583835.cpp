#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <iomanip>
#include <set>
using namespace std;

typedef long long ll;
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define SORT(s) sort((s).begin(),(s).end())

int main(){
    string S; cin >> S;
    set<char> t;

    for(auto c: S){
        t.insert(c);
    }
    
    if(t.size() == 4) cout << "Yes" << endl;
    else if(t.size() == 2){
        if((t.find('N') != t.end() && t.find('S') != t.end())
        ||  t.find('W') != t.end() && t.find('E') != t.end() ){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }else{
            cout << "No" << endl;
    }
    return 0;
}
