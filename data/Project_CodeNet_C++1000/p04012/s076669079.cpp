#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   // freopen("input.txt","r",stdin);
    string w;
    cin >> w;
    map<char,int> a;
    for(int i =0;i<w.size();i++){
        a[w[i]]++;
    }
    bool poss = true;
    for(auto x:a){
        if(x.second%2 != 0){
            poss = false;
        }
    }
    if(poss){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }

}
