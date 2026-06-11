#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    string s;
    cin >> s;
    
    vector<string> v = {"dream", "dreamer", "erase", "eraser"};
    
    for (int i=0; i<v.size(); i++){
        reverse(v[i].begin(), v[i].end());
    }
    
    int n = s.size();
    reverse(s.begin(), s.end());
    
    int i = 0;
    while(i < n){
        bool ok = false;
        for (int j=0; j<4; j++){
            bool flag = true;
            
            for (int k=0; k<v[j].size(); k++){
                if(s[i+k] != v[j][k]) flag = false;
            }
            if(flag){
                i += v[j].size()-1;
                // cout << v[j] << " " << i << endl;
                ok = true;
                if(i == n-1){
                    cout << "YES" << endl;
                    return 0;
                }
                break;
            }
        }
            if(!ok){
                cout << "NO" << endl;
                return 0;
            }
        i++;
    }
    cout << "NO" << endl;
}
