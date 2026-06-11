#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> P;
bool used[250000];

int main(){
    int N;
    int ans[250000];
    P x[500];
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        cin >> x[i].first;
        x[i].first--;
        x[i].second = i+1;
        used[x[i].first] = true;
        ans[x[i].first] = i+1;
    }
    sort(x, x+N);
    int idx = 0;
    for(int i = 0; i < N; i++){
        //cout << x[i].first << ' ' << x[i].second << endl;
        int n = x[i].second;
        int cnt = 0;
        while(cnt < n-1){
            if(idx > x[i].first){
                cout << "No" << endl;
                return 0;
            }
            if(!used[idx]) {
                cnt++;
                ans[idx] = n;
            }
            idx++;
        }
    }
    idx = N*N-1;
    for(int i = N-1; i >= 0; i--){
        //cout << x[i].first << ' ' << x[i].second << endl;
        int n = N-x[i].second;
        //cout << n << endl;
        int cnt = 0;
        while(cnt < n){
            if(idx < x[i].first){
                cout << "No" << endl;
                return 0;
            }
            if(!used[idx]) {
                cnt++;
                ans[idx] = x[i].second;
            }
            idx--;
        }
    }
    cout << "Yes" << endl;
    for(int i = 0; i < N*N; i++){
        cout << ans[i];
        if(i < N*N-1) cout << ' ';
        else cout << '\n';
    }
}