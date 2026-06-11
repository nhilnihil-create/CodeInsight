#include <bits/stdc++.h>
using namespace std;
int main(void){
    int N;
    cin >> N;
    map<int,int> mp;
    vector<int> V(1000,1001);
    for(int i = 2; i <= N; i++){
        bool flag = true;
        for(int j = 2; j < i; j++){
            if(i % j == 0){
                flag = false;
                break;
            }
        }
        if(flag == true) V[i] = i;
    }
    sort(V.begin(),V.end());

    for(int i = 2; i <= N; i++){
        int I = i;
        while(I > 1){
            for(int j = 0; V[j] != 1001; j++){
                while(I%V[j] == 0){
                    I /= V[j];
                    mp[V[j]]++;
                }
            }
        }
    }
    long long ans = 1;
    for(auto p : mp){
        ans *= p.second + 1;
        ans %= 1000000007;
        //cout << p.first << "  "<< p.second << endl;
    }
    cout << ans << endl;
}