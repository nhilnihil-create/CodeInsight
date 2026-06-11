#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n;
    string s;
    cin >> n >> s;
    vector<string> saisyo = {"SS", "SW", "WS", "WW"};
    for(i = 0;i < 4;++i){
        string tmp = saisyo.at(i);
        for(j = 1;j < n-1;++j){
            if(s.at(j) == 'o'){
                if(tmp.at(j) == 'S'){
                    tmp.push_back(tmp.at(j-1));
                }else{
                    if(tmp.at(j-1) == 'W'){
                        tmp.push_back('S');
                    }else{
                        tmp.push_back('W');
                    }
                }
            }else{
                if(tmp.at(j) == 'S'){
                    if(tmp.at(j-1) == 'W'){
                        tmp.push_back('S');
                    }else{
                        tmp.push_back('W');
                    }
                }else{
                    tmp.push_back(tmp.at(j-1));
                }
            }
        }
        bool flag = true;
        if(s.at(n-1) == 'o'){
            if(tmp.at(n-1) == 'S'){
                if(tmp.at(n-2) != tmp.at(0)) flag = false;
            }else{
                if(tmp.at(n-2) == tmp.at(0)) flag = false;
            }
        }else{
            if(tmp.at(n-1) == 'S'){
                if(tmp.at(n-2) == tmp.at(0)) flag = false;
            }else{
                if(tmp.at(n-2) != tmp.at(0)) flag = false;
            }
        }
        if(!flag) continue;
        if(s.at(0) == 'o'){
            if(tmp.at(0) == 'S'){
                if(tmp.at(1) != tmp.at(n-1)) flag = false;
            }else{
                if(tmp.at(1) == tmp.at(n-1)) flag = false;
            }
        }else{
            if(tmp.at(0) == 'S'){
                if(tmp.at(1) == tmp.at(n-1)) flag = false;
            }else{
                if(tmp.at(1) != tmp.at(n-1)) flag = false;
            }
        }
        if(!flag) continue;
        cout << tmp << endl;
        return 0;
    }
    cout << -1 << endl;
    return 0;
}