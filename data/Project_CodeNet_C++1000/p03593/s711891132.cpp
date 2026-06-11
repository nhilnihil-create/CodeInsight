#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(26, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char x;
            cin >> x;
            a[x - 'a']++;
        }
    }
    int tot = n*m;
    int a4 = (n/2)*(m/2); //cout << a4;
    tot -= a4*4;
    for(int i = 0; i < 26; i++){
        while(a[i]  >= 4 && a4 > 0){
            a[i] -= 4;
            a4--;
        }
    }
    
    if(a4) {
        cout << "No\n"; return 0;
    }

    if(tot == 0) {
        cout << "Yes\n"; return 0;
    }
    int a2 = (m/2)*(n%2) + (n/2)*(m%2);
    tot -= a2*2;
    for(int i = 0; i < 26; i++){
        while(a[i]  >= 2 && a2 > 0){
            a[i] -= 2;
            a2--;
        }
    }
    if(a2) {
        cout << "No\n"; return 0;
    }

    if(tot == 0) {
        cout << "Yes\n"; return 0;
    }
    for(int i = 0; i < 26; i++){
        if(a[i]) {
            cout << "Yes\n"; return 0;
        }
    }
    cout << "No";

}
