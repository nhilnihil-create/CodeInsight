#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(int i=0; i<n; i++)
#define reps(i, s, e) for(int i=s; i<e; i++)
#define repr(i, n) for(int i=n-1; i>=0; i--)
#define reprs(i, s, e) for(int i=e-1; i>=s; i--)

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    string s; cin >> s;

    int n = s.size();

    string t;
    rep(i, n){
        if(i % 2 == 0){
            t.push_back('g');
        }
        else{
            t.push_back('p');
        }
    }

    int score = 0;
    rep(i, n){
        if(t[i] == 'p' && s[i] == 'g'){
            score++;
        }
        if(t[i] == 'g' && s[i] == 'p'){
            score--;
        }
    }

    cout << score << endl;

    return 0;
}