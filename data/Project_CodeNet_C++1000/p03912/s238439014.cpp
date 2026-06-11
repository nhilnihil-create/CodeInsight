#include <bits/stdc++.h>
using namespace std;
 
const long long MOD = 1000000007;
const int INF = 1<<29;
const double EPS = 1e-8;
typedef vector<int> vec;
typedef pair<int,int> P;
typedef long long ll;


int main(){
    int N, M;
    cin >> N >> M;

    vec x_count(100001, 0);
    vec m_count(M, 0);
    for(int i=0;i<N;i++){
        int x;
        cin >> x;
        x_count[x]++;
        m_count[x % M]++;
    }

    int ans = 0;
    // for(int i=0;i<M;i++){
    //     cout << m_count[i];
    // }
    // cout << endl;
    for(int i=0;i<M;i++){
        if(i == 0 || 2 * i == M){
            int use = m_count[i];
            if(use <= 1) continue;
            if(use % 2 == 1) use--;
            m_count[i] -= use;
            ans += use / 2;
        }else{
            int use = min(m_count[i], m_count[M - i]);
            if(use <= 0) continue;
            m_count[i] -= use;
            m_count[M - i] -= use;
            ans += use;
            // cout << i << " " << M - i <<  " " << use << endl;
        }
    }
    // cout << ans << endl;
    // for(int i=0;i<M;i++){
    //     cout << m_count[i];
    // }
    // cout << endl;

    for(int i=1;i<=100000;i++){
        if(m_count[i % M] >= 2 && x_count[i] >= 2){
            int use = min(m_count[i % M], x_count[i]);
            if(use % 2 == 1) use--;
            x_count[i] -= use;
            m_count[i % M] -= use;
            ans += use / 2;
        }
    }

    cout << ans << endl;
    return 0;
}
