#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 1000000007;

struct Magic{
    vector<int> v;
    int delta;
    int b, e;

    Magic() {
        v = vi();
        delta = b = e = 0;
    }

    void append(int x){
        x -= delta;

        if (e == v.size())
            v.push_back(0);

        v[e++] = x;
    }

    int front(){
        return v[b] + delta;
    }

    int back(){
        return v[e - 1] + delta;
    }

    void pop_front(){
        b++;
    }

    bool empty(){
        return e == b;
    }

    void pop_back(){
        e--;
    }

    void sub(){
        delta--;

        if (!empty() && front() == 0)
            pop_front();
    }

    bool winner(){
        return front() & 1;
    }

    void enumerate(){
        for (int i = b; i < e; ++i)
            cout << v[i] + delta << " ";
        cout << endl;
    }

    void fix(){
        if (e - b >= 2 && v[e - 1] - 1 == v[e - 2]){
            pop_back();
        }
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; ++i){
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    Magic ds;

    ds.append(1);

    for (auto u : v){
        u++;
        ds.sub();
        ds.append(u);
        ds.fix();
    }

    cout << (ds.winner() ? "First" : "Second") << endl;

    return 0;
}