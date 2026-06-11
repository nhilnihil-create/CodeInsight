#include"bits/stdc++.h"
#include<unordered_set>
#include<unordered_map>
#include<random>
using namespace std;
typedef long long ll;
const ll MOD = (ll)(1e9+7);
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(int)(n); (i)++)
int dx[4]={ 1,0,-1,0 };
int dy[4]={ 0,1,0,-1 };

int N;
string S;

signed main(){
    cin >> N >> S;
    int l = 0;
    int n = 0;
    rep(i, N){
        if(S[i] == '(') n++;
        else{
            if(n > 0) n--;
            else{
                l++;
            }
        }
    }

    rep(i, l) cout << "(";
    cout << S;
    rep(i, n) cout << ")";
    cout << endl;
}