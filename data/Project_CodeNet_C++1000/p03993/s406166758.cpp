#include <bits/stdc++.h>
using namespace std;

int main(){

    int N;
    cin >> N;

    vector<int> a(N+1);
    for(int i=1; i<=N; i++) cin >> a.at(i);
    vector<bool> used(N+1, false);

    int cnt = 0;
    for(int i=1; i<=N; i++){
        if(used.at(i) == false){
            if(a.at(a.at(i)) == i){
                cnt++;
                used.at(i) = true;
                used.at(a.at(i)) = true;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}