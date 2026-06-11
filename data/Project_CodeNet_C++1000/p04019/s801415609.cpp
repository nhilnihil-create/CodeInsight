#include <bits/stdc++.h>
using namespace std;
using pint = pair<int,int>;

const long long INFLL = 1LL << 60;
const int INFI = 1000000000;


int main(){
    string S; cin >> S;
    vector<int> v(4,0);
    for(int i=0;i<S.size();i++){
        if(S[i] =='N') v[0]++;
        if(S[i] =='W') v[1]++;
        if(S[i] =='S') v[2]++;
        if(S[i] =='E') v[3]++;
    }
    int count =0;
    for(int i=0;i<4;i++) {if(v[i] == 0) count++;}
    if(count == 1 || count == 3) cout << "No" << endl;
    else if(v[0]*v[2] == 0 && v[1]*v[3] == 0) cout << "No" << endl;
    else cout << "Yes" << endl;
}


