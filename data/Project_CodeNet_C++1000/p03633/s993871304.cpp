#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T>
T gcd(T a, T b){
    T n = min(a,b);
    T m = max(a,b);
    if(n == 0){ return m;}
    else {
        return gcd(n, m % n);
    }
}

template<typename T>
T gcdAll(std::vector<T> & vals){
    int size = vals.size();
    T gcdVal = vals[0];
    for(int i = 1 ; i < size; i++){
        gcdVal = gcd(std::max(vals[i], gcdVal), std::min(vals[i], gcdVal));
    }
    return gcdVal;
}

int main(void)
{
    int N;
    cin >> N;
    vector<ll> T(N);
    for (int i = 0; i < N; i++)
    {
        cin >> T[i];        
    }

    ll lcmVal = T[0];
    for(int i = 1; i < N; i++){
        ll gcdVal = gcd(T[i] ,lcmVal);
        lcmVal = (T[i] / gcdVal) * lcmVal;
    }

    cout << lcmVal << endl;
    
    return 0;
}
