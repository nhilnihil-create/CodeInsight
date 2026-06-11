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

#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define ALL(v) (v).begin(), (v).end()
#define p(s) cout<<(s)<<endl
#define p2(s, t) cout << (s) << " " << (t) << endl
#define br() p("")
#define pn(s) cout << (#s) << " " << (s) << endl
#define p_yes() p("YES")
#define p_no() p("NO")

const ll mod = 1e9 + 7;
const ll inf = 1e18;

ll N, A, B;
vector<ll> H;

bool can_clear(ll num){
    auto V = H;
    
    // 全体にB*numダメージ
    FOR(i, 0, N){
        V[i] -= B*num;
    }

    ll C = A-B;
    // 残りCをnum回で倒せるか
    FOR(i, 0, N){
        if(V[i]>0){
            ll cast_num;
            if(V[i]%C==0){
                cast_num = V[i]/C;
            }else{
                cast_num = V[i]/C + 1;
            }
            
            num -= cast_num;
            if(num<0){
                return false;
            }
        }
    }
    return true;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    cin >> N >> A >> B;
    
    H.resize(N);
    FOR(i, 0, N){
        cin >> H.at(i);
    }

    ll left = 0; // 無理
    ll right = 2000000000; // 絶対可能

    while(left+1!=right){
        ll center = (left + right) / 2;        
        if(can_clear(center)){
            right = center;
        }else{
            left = center;
        }
    }

    p(right);
    
    return 0;
}