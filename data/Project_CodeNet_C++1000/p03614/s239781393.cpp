#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){
    int N;
    cin >> N;
    vector<int> p(N+1);
    for(int i = 1;i <= N;i++)   cin >> p[i];
    int ans = 0;
    for(int i = 1;i <= N;i++){
        if(p[i] == i){
            if(i < N)   swap(p[i], p[i+1]);
            else    swap(p[i], p[i-1]);
            ans++;
        }
    }
    cout << ans << endl;
}