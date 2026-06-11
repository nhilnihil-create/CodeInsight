#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    deque<int> b;
    if (n % 2 == 0) {
        for(int i = 0; i < n; i++){
            if(i % 2 == 1){
                b.push_front(a[i]);
            }
            else{
                b.push_back(a[i]);
            }
        }
    } 
    else {
        for(int i = 0; i < n; i++){
            if(i % 2 == 0){
                b.push_front(a[i]);
            }
            else{
                b.push_back(a[i]);
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << b[i] << ' ';
    }
    return 0;
}