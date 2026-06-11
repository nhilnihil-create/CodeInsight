#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <climits>
using namespace std;

string query(long long n, long long N){
    string ret;
    if( (n <= N && to_string(n) <= to_string(N)) || (n > N && to_string(n) > to_string(N)) ) ret = "Y";
    else ret = "N";
    return ret;
}

long long solve(int n){
    vector<bool> v1(11, false);
    vector<bool> v2(11, false);
    long long fac = 1;
    for(int i=0; i<11; i++){
        string s;
        //s = query(n, fac);
        cout << "? " + to_string(fac) << endl;
        cin >> s;
        if(s == "Y") v1[i] = true;
        //s = query(n, 2 * fac);
        cout << "? " + to_string(2 * fac) << endl;
        cin >> s;
        if(s == "Y") v2[i] = true;
        fac *= 10;
    }

    int d;
    for(int i=0; i<11; i++){
        if(v1[i] == true) d = i + 1;
    }
    if(d == 11){
        for(int i=0; i<11; i++)
            if(v2[i] == true){
                d = i + 1;
                break;
            }
    }

    long long lb = 0, ub = 0;
    fac = 1;
    for(int i=0; i<d; i++){
        ub += 9 * fac;
        fac *= 10;
    }
    lb = fac / 10;

    string s;
    //s = query(n, lb * 10);
    cout << "? " + to_string(lb * 10) << endl;
    cin >> s;
    if(s == "Y") return lb;

    long long ans;
    while(ub - lb > 1){
        string s;
        ans = (ub + lb) / 2;
        //s = query(n, ans * 10);
        cout << "? " + to_string(ans * 10) << endl;
        cin >> s;
        if(s == "Y") ub = ans;
        else lb = ans;
    }
    return ub;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    long long ans = solve(0);
    cout << "! " + to_string(ans) << endl;
    return 0;
}