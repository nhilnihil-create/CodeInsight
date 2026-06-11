#include <iostream>
#include<bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

#define long long ll

int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> pre_cnt(n,vector<int>(26,0));
    char temp;
    int base = int('a');
    rep(i,n){
        temp = s[i];
        pre_cnt[i] = pre_cnt[max(i-1,0)];
        pre_cnt[i][int(temp)-base] += 1;
    }
    int cnt ;
        if (s.size() < 2){
            cout << -1 << " " << -1 << endl;
            return 0;                
        }
        if ( s.size() == 2 ){
        int max_cnt = 0;
        for(int k=0; k < 26; k++){
            cnt = pre_cnt[1][k] ;
            max_cnt = max(max_cnt,cnt);
        }
        if (max_cnt*2 > 2 ){
            cout << 1 << " " << 2 << endl;
            return 0;
        } else{
            cout << -1 << " " << -1 << endl;
            return 0;            
        }
    }                       
    rep(i,n){

        for(int j=i+2; j < min(n,i+3); j++){
            int max_cnt = 0;
            if(i > 0){
                for(int k=0; k < 26; k++){
                    cnt = pre_cnt[j][k] - pre_cnt[i-1][k] ;
                    max_cnt = max(max_cnt,cnt);
                }
            }else{
                for(int k=0; k < 26; k++){
                    cnt = pre_cnt[j][k] ;
                    max_cnt = max(max_cnt,cnt);
                }
            }
            if ( i > 0){
                if (max_cnt*2 > j-i+1 ){
                    cout << i+1 << " " << j+1 << endl;
                    return 0;
                }
            }else{
                if (max_cnt*2 > j+1 ){
                    cout << 1 << " " << j+1 << endl;
                    return 0;
                }                
            }
        }
    }
    cout << -1 << " " << -1 << endl;
    return 0;
}
