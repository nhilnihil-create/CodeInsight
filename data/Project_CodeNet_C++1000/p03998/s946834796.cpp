#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1LL << 60;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string sa,sb,sc;
    cin >> sa >> sb >> sc;
    ll na = sa.size();
    ll nb = sb.size();
    ll nc = sc.size();
    ll ta = 0;
    ll tb = 0;
    ll tc = 0;
    deque<char> da(na);
    deque<char> db(nb);
    deque<char> dc(nc);

    for (ll i = 0; i < na; i++){
        da[i] = sa[i];
    }
    for (ll i = 0; i < nb; i++){
        db[i] = sb[i];
    }
    for (ll i = 0; i < nc; i++){
        dc[i] = sc[i];
    }

    char now = 'a';

    while (true){
        if (now == 'a'){
            if (da.size() == 0){
                cout << "A" << endl;
                break;
            }
            now = da[0];
            da.pop_front();
        }
        if (now == 'b'){
            if (db.size() == 0){
                cout << "B" << endl;
                break;
            }
            now = db[0];
            db.pop_front();
        }
        if (now == 'c'){
            if (dc.size() == 0){
                cout << "C" << endl;
                break;
            }
            now = dc[0];
            dc.pop_front();
        }
    }

}