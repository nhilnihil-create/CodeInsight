#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define p pair<int,int>
const int inf = 1 << 30;
template<class T> void chmin(T& x, T y){if(x > y) x = y;}
template<class T> void chmax(T& x, T y){if(x < y) x = y;}
int N;
int a[250010];
int ans[250010];
bool flag = true;


int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        int x;
        cin >> x;
        a[x] = i;
    }
    int l = 1;
    for(int i = 1; i <= N * N; i++){
        if(a[i] == 0) continue;
        ans[i] = a[i];
        
        int d = a[i] - 1;
        for(; l <= i && d > 0; l++){
            if(ans[l] == 0){
                ans[l] = a[i];
                d--;
            }
        }
        if(d != 0){
            flag = false;
        } 
    }
    int r = N * N;
    for(int i = N * N; i >= 1; i--){
        if(a[i] == 0) continue;

        int d = N - a[i];
        for(; r >= i && d > 0; r--){
            if(ans[r] == 0){
                ans[r] = a[i];
                d--;
            }
        }
        if(d != 0){
            flag = false;
        }
    }
    if(flag){
        cout << "Yes" << endl;
        for(int i = 1; i <= N * N; i++) cout << ans[i] << " ";
        cout << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}