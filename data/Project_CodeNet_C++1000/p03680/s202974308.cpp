#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> check(n, 0);
    int tmp = 1, count = 0;
    while(tmp != 2){
        if(check[tmp - 1] == 1){
            count = -1;
            break;
        }
        check[tmp - 1] = 1;
        tmp = a[tmp - 1];
        count++;
    }
    cout << count << endl;
}