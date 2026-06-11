#include<iostream>
#include<map>

#define ll long long

using namespace std;

int main(){
    int n, a, b;
    ll k;
    cin >> n >> k;

    map<int, ll> m;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        if(m.find(a) == m.end()){
            m[a] = b;
        }else{
            m[a] += b;
        }
    }

    map<int, ll> :: iterator ite = m.begin();
    while(ite != m.end()){
        if(ite -> second < k){
            k -= ite -> second;
        }else{
            cout << ite -> first << endl;
            break;
        }
        ite++;
    }
}