#include<bits/stdc++.h>
#define D 1000000007
using namespace std;
using ull = long long;
ull func(ull x){
    if(x==1 || x==0) return 1;
    else{
        return x * func(x-1);
    }
}

int main(){
    ull n, m; cin >> n >> m;
    ull ans =0;
    ull n_func=1, m_func=1;
    if(n-m > 1 || m-n > 1){
        cout << 0 << endl;
        return 0;
    }
    for(int i=n; i>=1; i--){
        n_func = n_func*i;
        n_func = n_func%D;
    }
    for(int i=m; i>=1; i--){
        m_func = m_func*i;
        m_func = m_func%D;
    }
    ans = n_func * m_func;
    if(n==m) ans = ans*2;
    ans = ans%D;

    cout << ans << endl;
    return 0;
    
}