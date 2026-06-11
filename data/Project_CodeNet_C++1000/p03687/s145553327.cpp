#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int maxi , len , mini;
string a;
vector<int>v;
char c;
int main(){
    cin >> a;
    len = a.size();
    mini = 300;
    for(int i = 0 ; i < len ; i++){
        c = a[i];
        v.clear();
        
        v.pb(0);
        for(int j = 0 ; j < len ; j++){
            if(a[j] == c){
                v.pb(j);
            }
        }
        v.pb(len - 1);
    
        maxi = 0;
        for(int j = 1 ; j < v.size() ; j++){
            if(j == 1 || j == v.size() - 1)maxi = max(maxi , v[j] - v[j - 1]);
            else maxi = max(maxi , v[j] - v[j - 1] - 1);
        }
        mini = min(mini , maxi);
    }
    cout << mini << endl;
}