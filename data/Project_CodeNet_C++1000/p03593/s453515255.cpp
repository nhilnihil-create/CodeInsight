 #include<bits/stdc++.h>
using namespace std;

int main(){
    int H, W;
    cin >> H >> W;
    map<char,int> mp;
    for(int h = 0; h < H; h++){
        for(int w = 0; w < W; w++){
            char a; cin >> a;
            mp[a]++;
        }
    }

    int one = 0;
    int two = 0;
    int four = 0;
    if((H & 1) && (W & 1)) one = 1;
    if(H & 1) two += (W / 2);
    if(W & 1) two += (H / 2);
    four = (H / 2) * (W / 2);

    for(auto& p : mp){
        while(four && p.second >= 4){
            p.second -= 4;
            four--;
        }
    }
    for(auto& p : mp){
        while(two && p.second >= 2){
            p.second -= 2;
            two--;
        }
    }
    for(auto& p : mp){
        while(one && p.second >= 1){
            p.second--;
            one--;
        }
    }

    bool yes = true;
    for(auto& p : mp){
        yes &= (!p.second);
    }
    yes &= (!one & !two & !four);

    if(yes) cout << "Yes" << endl;
    else cout << "No" << endl;
}
