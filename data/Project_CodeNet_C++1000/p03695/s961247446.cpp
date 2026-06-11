#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> rate(9, 0);
    for(int x : a){
        int ite = 0, b = 400;
        while(ite < 8){
            if(x < b){
                rate[ite] = 1;
                break;
            }
            ite++;
            b += 400;
        }
        if(ite == 8) rate[8] += 1;
    }
    int sum = 0;
    for(int i = 0; i < 8; i++){
        sum += rate[i];
    }
    cout << max(1, sum) << ' ' << sum + rate[8] << endl;
}