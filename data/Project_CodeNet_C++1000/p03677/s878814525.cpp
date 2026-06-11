#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>
#include <stack>
#include <complex>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define fs first
#define sc second

ll a[100100];
ll b[100100];
ll m_num[100100];

int n, m;

ll dif(ll x, ll y){
    if(x <= y){
        return y - x;
    }
    else{
        return y + m - x;
    }

}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int aa; cin >> aa;
        a[i] = aa - 1;
    }

    fill(b, b+m+10, 0);
    fill(m_num, m_num+m+10, 0);

    for(int i = 1; i < n; i++){
        int up = dif(a[i-1], a[i]);  //upが0になることはない
        b[a[i]+1] += up - 1;   //m = a[i]からm=a[i]+1にしたときに増える量


        if((a[i-1] + 2) % m == (a[i] + 1) % m){
            continue;
        }
        else if((a[i-1] + 2) < a[i] + 1){
            m_num[a[i-1] + 2]++;
            m_num[(a[i] + 1)]--;
        }
        else if((a[i-1] + 2) > (a[i] + 1)){
            if(a[i-1] == m-1){
                m_num[1]++;
                m_num[(a[i] + 1)]--;
            }
            else{
                m_num[a[i-1] + 2]++;
                m_num[(a[i] + 1)]--;
                m_num[0]++;
            }

        }
    }
    //cout << endl;

    //cout << 0 << " " << m_num[0] << endl;
    for(int i = 1; i < m; i++){
        //cout << i << " " << m_num[i] << endl;
        m_num[i] += m_num[i-1]; //imos
        //cout << m_num[i] << endl;
        //cout << endl;
    }
    //cout << endl;

    ll res = 0;  //m = 0のとき
    for(int i = 1; i < n; i++){
        res += min(dif(a[i-1], a[i]), dif(0, a[i]) + 1);
    }
    ll res_tmp = res;
    for(int m_tmp = 1; m_tmp < m; m_tmp++){
        res_tmp += b[m_tmp];
        res_tmp -= m_num[m_tmp];
        if(res_tmp < 0){
            cout << m_tmp << endl;
            cout << m_num[m_tmp] << endl;
            cout << res_tmp << endl;
            return 0;
        }
        res = min(res, res_tmp);
    }

    cout << res << endl;

    return 0;
}
