#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
    ll H,W;
    cin >> H >> W;
    map<char,int> mp;
    ll edge_4 = 0;
    ll edge_2 = 0;
    ll center = 0;

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            char tmp;
            cin >> tmp;
            mp[tmp]++;
            if(mp[tmp] % 4 == 0){
                mp[tmp] = 0;
                edge_4++;
            }
        }
    }

    for(int i = 0; i < 26; i++){
        if(mp['a' + i] == 2){
            edge_2++;
        }else if(mp['a' + i] == 1){
            center++;
        }
    }

    if(H % 2 == 0 && W % 2 == 0){
        if(edge_4 == (H * W) / 4){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    else if(H % 2 == 1 && W % 2 == 1){

        if(center == 1 && (H * W - (center + 2 * edge_2)) % 4 == 0 && edge_4 == (H * W - (center + 2 * edge_2)) / 4){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    else{
        if((H * W - (2 * edge_2)) % 4 == 0 && edge_4 == (H * W - (2 * edge_2)) / 4){
            if((H % 2 == 0 && 2 * edge_2 <= H) || (W % 2 == 0 && 2 * edge_2 <= W)){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
                
        }else{
            cout << "No" << endl;
        }
    }

}


