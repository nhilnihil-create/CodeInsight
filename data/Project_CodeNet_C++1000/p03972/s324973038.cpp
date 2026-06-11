#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, int>P;
int main(){
    long long w, h, ans = 0;
    cin>>w>>h;
    vector<P>vec(w+h);
    for(int i=0;i<w;i++){
        cin>>vec[i].first;
        vec[i].second=0;
    }
    for(int i=0;i<h;i++){
        cin>>vec[w+i].first;
        vec[w+i].second=1;
    }
    sort(vec.begin(), vec.end());
    long long cols = w + 1, rows = h + 1;
    for(int i=0;i<vec.size();i++){
        if(vec[i].second){
            ans += vec[i].first * cols;
            rows--;
        }
        else{
            ans += vec[i].first * rows;
            cols--;
        }
    }
    cout<<ans<<endl;

    return 0;
}