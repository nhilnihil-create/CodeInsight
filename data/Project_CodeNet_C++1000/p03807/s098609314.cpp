#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 100100100100;


ll combination(ll n, ll r){
    if(n < r) return 0;
    if(r == 0||r == n) return 1;
    else if(r == 1) return n;
    return (combination(n - 1, r - 1) + combination(n - 1, r));
}

bool checkKaibun(string str){
    string checkStr = str;
    reverse(checkStr.begin(), checkStr.end());
    if(str == checkStr) return true;
    else return false;
}

int keta(ll num){
    int digits = 0;
    while(num > 0){
        num /= 10;
        digits++;
    }
    return digits;
}


int main(){
    int N;
    cin >> N;
    int even = 0, odd = 0;
    rep(i, N){
        int num;
        cin >> num;
        if(num % 2 == 0) even++;
        else odd++;
    }
    if(odd % 2 == 1)cout << "NO" << endl;
    else cout << "YES" << endl;
}