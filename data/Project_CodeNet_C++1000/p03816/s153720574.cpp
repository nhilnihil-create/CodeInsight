#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());

    int x = 1;
    vector<int> cards;
    for(int i=0; i<n; i++){
        if(a[i] == a[i+1]) x += 1;
        if(a[i] != a[i+1]){
            cards.push_back(x);
            x = 1;
        }
    }

    int m = cards.size();
    cout << m - (1 - m % 2) << endl;
    return 0;
}