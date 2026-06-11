#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    int N;
    cin >> N;
    string s;
    cin >> s;
    int l=0;int r=0;
    int lappendNum =0; 
    for(int i=0;i<N;i++){
        if(s[i] == '('){
            l++;
        }else{
            r++;
        }
        if(l<r){
            l++;
            lappendNum++;
        }
    }
    string ans ="";
    for(int i=0;i<lappendNum;i++){
        ans += '(';
    }
    ans += s;
    for(int i=0;i<(l-r);i++){
        ans += ')';
    }
    cout << ans << endl;

    return 0;
}