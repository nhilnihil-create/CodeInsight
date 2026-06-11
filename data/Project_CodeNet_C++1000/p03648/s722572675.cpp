#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
using tpl = tuple<int, int, int>;
typedef pair<int,int> pii;

void fastStream(){cin.tie(0);std::ios_base::sync_with_stdio(0);}


ll K;
int main(){
    
    cin >> K;
    if(K % 50 == 0){
        cout << 50 << endl;
        for(int i = 0; i < 50; i++){
            cout << 49 + K / 50 << " ";
        }
        cout << endl;
    }
    else{
        vector<ll> a(50, (K + 49) / 50 + 49);
        for(int i = 0; i < 50 - (K % 50); i++){
            int max_idx = 0;
            for(int j = 1; j < (int)a.size(); j++){
                if(a[j] > a[max_idx]){
                    max_idx = j;
                }
            }
            for(int j = 0; j < (int)a.size(); j++){
                if(j == max_idx){
                    a[j] -= 50;
                }
                else{
                    a[j]++;
                }
            }
        }
        cout << 50 << endl;
        for(ll t : a){
            cout << t << " ";
        }
        cout << endl;
    }

    return 0;
}

