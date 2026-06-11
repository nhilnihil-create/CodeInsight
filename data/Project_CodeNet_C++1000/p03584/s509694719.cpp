#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int n, k;
vector<vector<int>> bi;
vector<int> val, target(32, 0);

ll f(vector<int> v){
    ll ret = 0;
    for(int i = 0; i < n; i++){
        bool valid = true;
        for(int j = 0; j < 32; j++){
            valid &= (v[j] >= bi[i][j]);
        }
        if(valid)   ret += val[i];
    }
    return ret;
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        if(a > k)   continue;
        vector<int> tmp(32, 0);
        for(int j = 0; j < 32; j++) tmp[j] = a % 2, a /= 2;
        bi.push_back(tmp);
        val.push_back(b);
    }
    n = val.size();
    for(int i = 0; i < 32; i++) target[i] = k%2, k /= 2;
    int msb = 0;
    for(int i = 0; i < 32; i++){
        if(target[i] == 1)  msb = i;
    }
    ll ans = f(target);
    for(int i = msb-1; i >= 0; i--){
        if(target[i] == 0)  continue;
        vector<int> cp = target;
        cp[i] = 0;
        for(int j = i-1; j >= 0; j--)   cp[j] = 1;
        ans = max(ans, f(cp));
    }
    target[msb] = 0;
    for(int i = msb-1; i >= 0; i--) target[i] = 1;
    ans = max(ans, f(target));
    cout << ans << endl;
    return 0;
}