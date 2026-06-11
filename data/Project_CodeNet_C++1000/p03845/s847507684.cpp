#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    IOS;
    int n;
    cin >> n;
    vector<int> T;
    for(int i=0; i<n; i++){
        int t;
        cin >> t;
        T.push_back(t);
    }
    int m;
    cin >> m;
    vector<int> vec;
    for(int i=0; i<m; i++){
        int p,x;
        cin >> p >> x;
        int count = 0;
        for(int j=0; j<T.size(); j++){
            if(j!=p-1){
                count+=T[j];
            }
        }
        cout << count + x <<endl;
    }  
}