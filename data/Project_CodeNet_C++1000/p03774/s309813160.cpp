#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> s(n, vector<int>(2));
    vector<vector<int>> c(m, vector<int>(2));
    //cout << "here" << endl;
    // input data
    for (int i=0; i<n; i++){
        cin >> s.at(i).at(0);
        cin >> s.at(i).at(1);
    }
    for (int i=0; i<m; i++){
        cin >> c.at(i).at(0);
        cin >> c.at(i).at(1);
    }
    //cout << "here" << endl;
    // calculate result 
    vector<int> ans(n);
    for (int i=0; i<n; i++){
        int min_d=0;
        int ans_num=1;
        for (int j=0; j<m; j++){
            int now_d=abs(s.at(i).at(0)-c.at(j).at(0))+abs(s.at(i).at(1)-c.at(j).at(1));
            if (j==0){
                min_d=now_d;
            } else {
                if (min_d>now_d){
                    ans_num=j+1;
                    min_d=now_d;
                }
            }
        }
        ans.at(i)=ans_num;
        //cout << "here" << endl;
    }
    //cout << "here" << endl;
    // print ans   
    for (int i=0; i<n; i++){
        cout << ans.at(i) << endl;
    }
}