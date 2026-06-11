#include <bits/stdc++.h>
using namespace std;

int main(){
    int w,h;
    cin >> w >> h;
    vector<pair<long long,bool>> v;
    for(int i=0; i<w; i++){
        long long t;
        cin >> t;
        v.push_back(make_pair(t,true));
    }
    for(int i=0; i<h; i++){
        long long t;
        cin >> t;
        v.push_back(make_pair(t,false));
    }
    sort(v.begin(),v.end());
    long long ans = 0;
    for(auto p = v.begin(); p != v.end(); p++){
        if((*p).second){
            ans += (*p).first * (h+1);
            w--;
        }
        else{
            ans += (*p).first * (w+1);
            h--;
        }
    }
    cout << ans << endl;
    return 0;
}
