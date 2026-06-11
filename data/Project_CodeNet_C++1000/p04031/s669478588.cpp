#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int target = 0;
    for(int i : a){
        target += i;
    }
    if((10*target / n)% 10 >= 5) target = target/n + 1;
    else target = target/n;

    int cost = 0;
    for(int i : a){
        cost += pow(i - target, 2);
    }
    cout << cost << endl;
}