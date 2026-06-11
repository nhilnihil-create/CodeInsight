#include <bits/stdc++.h>
using namespace std;

typedef long long  ll;

ll MOD = 1000000007;
ll INF = 100000000000;
double PI = 3.1415926535;

template<typename T>
void remove(std::vector<T>& vector, unsigned int index)
{
    vector.erase(vector.begin() + index);
}

ll GCD(ll a,ll b){
    if(a < b)return GCD(b,a);
    ll r = INF;
    while(r){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(){
   int N,K = 0,A;
   cin >> N;
   map<int,int> mp;
   for(int i = 0;i < N;i++){
       cin >> A;
       if(mp[A] == 0){
           K++;
       }
       mp[A]++;
   }
   if(K % 2 == 1){
       cout << K << endl;
   }else{
       cout << K - 1 << endl;
   }
}
