#include<bits/stdc++.h>
using namespace std;
#define int long long
//#undef int
#define mk make_pair
#define pb push_back
typedef pair<int, int> pii;
const int mod = 1000000007;
const int INF = 1000000009;
const long long INFL = 1000000000000000018ll;

int N, a[100100], b[100100];
bool fre[100100], fre2[100100];

signed main()
{
    cin >> N;
    bool flag = false;
    fre[0] = true;
    fre2[N - 1] = true;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        if(i > 0){
            if(a[i] < a[i - 1]){
                flag = true;
            }
            if(a[i] > a[i - 1]){
                fre[i] = true;
            }
        }
    }
    for(int i = 0; i < N; i++){
        cin >> b[i];
        if(i > 0){
            if(b[i] > b[i - 1]){
                flag = true;
            }
            if(b[i] < b[i - 1]){
                fre2[i - 1] = true;
            }
        }
    }
    if(a[N - 1] != b[0]){
        flag = true;
    }
    for(int i = 0; i < N; i++){
        if(fre[i] && fre2[i]){
            if(a[i] != b[i]){
                flag = true;
            }
        }
        else if(fre[i]){
            if(a[i] > b[i]){
                flag = true;
            }
        }
        else if(fre2[i]){
            if(a[i] < b[i]){
                flag = true;
            }
        }
    }
    if(flag){
        printf("0\n");
        return 0;
    }
    int ans = 1;
    for(int i = 0; i < N; i++){
        if(fre[i] || fre2[i])continue;
        ans = ans * min(a[i], b[i]) % mod;
    }
    cout << ans << endl;


    return 0;
}
/*



*/
