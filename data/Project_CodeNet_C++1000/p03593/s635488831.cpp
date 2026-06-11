#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h, w;
    cin >> h >> w;
    map<char, int> cnt;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            char a;
            cin >> a;
            cnt[a]++;
        }
    }
    int cnt_4 = (h/2)*(w/2);
    int cnt_2, cnt_1;
    if((h*w)%2 == 1) cnt_1 = 1;
    else cnt_1 = 0;
    cnt_2 = (h*w - cnt_4*4 - cnt_1)/2;
    vector<int> v;
    for(auto p : cnt){
        v.push_back(p.second);
    }
    for(auto p : v){
        while(p-4 >= 0 && cnt_4 > 0){
            p -= 4;
            cnt_4--;
        }
        while(p-2 >= 0 && cnt_2 > 0){
            p -= 2;
            cnt_2--;
        }
        while(p-1 >= 0 && cnt_1 > 0){
            p--;
            cnt_1--;
        }
    }
    if(cnt_1 == 0 && cnt_2 == 0 && cnt_4 == 0)
        cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}