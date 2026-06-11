#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<complex>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
#define PI 3.1415926535897932384626433832795028
typedef long long Int;
typedef pair<Int, Int> P;
typedef long double Real;
typedef complex<Real> CP;

int nxt_pos[26];
int nxt[220000];
int nxt_alphabet[220000];
int far[220000];
int main(){
    string str;
    cin >> str;
    int n = str.size();
    far[n] = 1;
    fill(nxt_pos, nxt_pos + 26, n);
    for(int i = str.size() - 1;i >= 0;i--){        
        far[i] = n;
        for(int j = 0;j < 26;j++){
            if(far[nxt_pos[j]] + 1 < far[i]){
                far[i] = far[nxt_pos[j]] + 1;
                nxt[i] = nxt_pos[j];
                nxt_alphabet[i] = j;
            }
        }
        nxt_pos[str[i] - 'a'] = i;
    }
    int start_alphabet;
    int start = 0;
    for(int i = 0;i < 26;i++){
        if(far[nxt_pos[i]] < far[nxt_pos[start]]){
            start = i;
        }
    }
    string ans = "";
    ans += 'a' + start;
    for(int pos = nxt_pos[start];pos < n;pos = nxt[pos]){
        ans += 'a' + nxt_alphabet[pos];        
    }
    cout << ans << endl;
    return 0;
}