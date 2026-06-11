#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> s(100);
    int nten=100;
    bool flg =false;
    int sum =0;
    for(int i=0; i<n; i++){
        cin >> s[i];
        sum += s[i];
        if(s[i]%10 != 0){
            flg =true; 
            nten = min(nten, s[i]);
        }
    }
    if(flg){
        if(sum%10 != 0){
            cout << sum << endl;
        }else{
            cout << (sum - nten) << endl;
        }
    }else{
        cout << "0" << endl;
    }
    return 0;
}