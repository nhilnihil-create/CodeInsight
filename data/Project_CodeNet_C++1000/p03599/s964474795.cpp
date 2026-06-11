#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    a = a * 100;
    b = b * 100;

    set<int> water;
    for(int i = 0; i <= 30; i++){
        for(int j = 0; j <= 30; j++){
            if(i != 0 || j != 0){
                if(a * i + b * j <= f){
                    water.insert(a * i + b * j);
                }
            }
        }
    }

    set<int> suger;
    for(int i = 0; i <= 3000; i++){
        for(int j = 0; j <= 3000; j++){
            if(c * i + d * j <= f){
                suger.insert(c * i + d * j);
            }
        }
    }

    vector<pair<int, int>> ans;
    for(auto itr = water.begin(); itr != water.end(); ++itr){
        for(auto itr_2 = suger.begin(); itr_2 != suger.end(); ++itr_2){
            int k = *itr / 100;
            k *= e;
            if(k >= *itr_2 && *itr + *itr_2 <= f){
                ans.push_back(make_pair(*itr, *itr_2));
            }
        }
    }

    double ans_q = 0;
    int flag = 0;
    for(int i = 0; i < ans.size(); i++){
        double k = ans[i].second * 100.0 / (ans[i].first + ans[i].second);
        if(k > ans_q){
            ans_q = k;
            flag = i;
        }
    }

    cout << ans[flag].first + ans[flag].second << " " << ans[flag].second << endl;

}