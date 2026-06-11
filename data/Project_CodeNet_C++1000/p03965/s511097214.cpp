#include<algorithm>
#include<complex>
#include<ctype.h>
#include<iomanip>
#include<iostream>
#include<map>
#include<math.h>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<stdio.h>
#include<string>
#include<string>
#include<vector>

using namespace std;
typedef long long ll;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(v) (v).begin(), (v).end()
#define p(s) cout<<(s)<<endl
#define p2(s, t) cout << (s) << " " << (t) << endl
#define pn(s) cout << (#s) << " " << (s) << endl
#define p_yes() p("Yes")
#define p_no() p("No")

const ll mod = 1e9 + 7;
const ll inf = 1e18;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    string s;
    cin >> s;

    ll gu_num = 0;
    ll pa_num = 0;

    ll score = 0;

    for(char c : s){
        if(c == 'p'){
            if(pa_num < gu_num){
                pa_num++;
            }else{
                gu_num++;
                score--;
            }
        }else{
            if(pa_num < gu_num){
                pa_num++;
                score++;
            }else{
                gu_num++;
            }
        }
    }

    p(score);
    
    return 0;
}
