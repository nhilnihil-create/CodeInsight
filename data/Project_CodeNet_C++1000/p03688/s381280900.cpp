#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

int main(){
    int n;
    cin >> n;
    map<int, int> mp;
    for(int i=0;i<n;++i){
        int a;
        cin >> a;
        mp[a]++;
    }
    if((int)mp.size() > 2)cout << "No";
    else{
        vector<pair<int, int>> v;
        for(auto e: mp)v.push_back(e);
        if((int)v.size() == 1){
            bool flag = false;
            for(int m=v[0].first;m<=v[0].first+1;++m){
                int a = max(0, 2-(n-2*(m-1)));
                int b = (n-(m-1) > 1 ? m-1 : m);
                if(mp[m-1] >= a && mp[m-1] <= b){
                    flag = true;
                    break;
                }
            }
            if(flag)cout << "Yes";
            else cout << "No";
        }else{
            int m = v[1].first;
            int a = max(0, 2-(n-2*(m-1)));
            int b = (n-(m-1) > 1 ? m-1 : m);
            if(mp[m-1] < a || mp[m-1] > b)cout << "No";
            else cout << "Yes";
        }
    }
    cout << endl;

    return 0;
}