#include<bits/stdc++.h> 
//#define <- プログラムの文字列を置換する
//typedef <- 新しい型に名前を付けるためのキーワード

using namespace std;

#define MAX_N 1

typedef long long ll;

const double PI = 3.141592653589793;
const long long MOD = 1e9 + 7;
const long long INF = 1e15;
const int INF_INT = 1e9;

int main(){
    int N;
    cin >> N;
    map<ll,int> m;
    vector<ll> a;
    for(int i = 0; i < N; i++){
        ll b;
        cin >> b;
        a.emplace_back(b);
        m[b]++;
    }
    sort(a.begin(),a.end(),greater<>());
    ll maxi = 0;
    ll maxi2 = -1;
    for(auto num : a){
        auto ite = m.find(num);
        if(ite -> second >= 4) {
            maxi = maxi2 = ite -> first;
            break;
        }
        else if(ite -> second >= 2) {
            maxi = ite -> first;
            break;
        } 
    }
    if(maxi == maxi2) {
        cout << maxi * maxi2 << endl;
        return 0;
    }
    for(auto num : a){
        auto ite = m.find(num);
        if(ite -> first == maxi) continue;
        if(ite -> second >= 2) {
            maxi2 = ite -> first;
            break;
        } 
    }
    cout << maxi * maxi2 << endl;
    return 0;
}
