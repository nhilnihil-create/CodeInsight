#include <bits/stdc++.h>
#define rep(i , n) for (int i = 0; i < (int)(n); i++)
const int INF = 1<<29;
using namespace std;
using ll = long long;
int main(){
    int N , M;
    cin >> N >> M;
    vector <int> a(M) , b(M);
    for(int i = 0; i < M; i++){
        cin >> a[i] >> b[i];
    }
    vector <int> c;
    int C = 0;
    bool t = false;
    for(int i = 0; i < M; i++){
        if(b[i] == N){
            c.push_back(a[i]);
            C++;
        }
    }
    for(int i = 0; i < M; i++){
        if(a[i] == 1){
            c.push_back(b[i]);
            C++;
        }
    }
    sort(c.begin() , c.end());
    for(int i = 0; i < C - 1; i++){
        if(c[i] == c[i + 1]){
            t = true;
        }
    }
    if(t){
        cout << "POSSIBLE" << endl;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }
}