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
    int n,a,b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int dom=0,ove=0;
    REP(i,n){
        if(s[i]=='a'){
            if(dom+ove < a+b){
                cout << "Yes" << endl;
                dom++;
            }else{
                cout << "No" << endl;
            }
        }
        else if(s[i]=='b'){
            if(dom+ove < a+b && ove < b){
                cout << "Yes" << endl;
                ove++;
            }else{
                cout << "No" << endl;
            }
        }else{
            cout << "No" << endl;
        }
    }
    return 0;
}