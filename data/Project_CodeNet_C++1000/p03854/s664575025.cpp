#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define sp <<" "<<
#define cst(x) cout<<fixed<<setprecision(x)
#define pi 3.14159265359
#define mod 1000000007
using namespace std;
using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;
using que_a = priority_queue<int, vector<int>, greater<int> >;
using que_d = priority_queue<int>;
using pint = pair<int,int>;

int main(){

    string s; cin >> s;
    bool ok = false;
    while(true){
        int len = s.size();
        if(len >= 5 && s.substr(len - 5) == "dream"){
            s.erase(len - 5);
        }
        else if(len >= 7 && s.substr(len - 7) == "dreamer"){
            s.erase(len - 7);
        }
        else if(len >= 5 && s.substr(len - 5) == "erase"){
            s.erase(len - 5);
        }
        else if(len >= 6 && s.substr(len - 6) == "eraser"){
            s.erase(len - 6);
        }
        else break;
        if(s.size() == 0){
            ok = true;
            break;
        }
    }
    if(ok) cyes;
    else cno;
    return 0;   
}
