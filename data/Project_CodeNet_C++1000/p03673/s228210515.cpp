#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> ans(n);
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            ans[i/2] = a[n-1-i];
        }else{
            ans[n-(i+1)/2] = a[n-1-i];
        }
    }

    for(int i = 0; i < n; i++){
        cout << ans[i];
        if(i != n-1) cout << " ";
        else cout << endl;
    }
} 