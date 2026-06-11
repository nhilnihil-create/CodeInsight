#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    string O, E;
    cin >> O >> E;
    vector<char> ans(O.size() + E.size());

    for(int i = 0; i < O.size() + E.size(); i++){
        if(i % 2 == 0){
            ans[i] = O[i / 2];
        }else{
            ans[i] = E[(i - 1)/2];
        }
    }

    for(int i = 0; i < ans.size(); i++) cout << ans[i];
    cout << endl;
}
