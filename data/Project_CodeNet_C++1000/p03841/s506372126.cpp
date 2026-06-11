#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int n;
vector <int> b;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    b.resize(n);
    for(auto &i : b){
        cin >> i;
        i--;
    }
    vector <int> p;
    for(int i = 0 ; i < n ; i++){
        p.push_back(i);
    }
    sort(p.begin(), p.end(), [&](int l, int r){
        return b[l] < b[r];
    });
    int pt = 0;
    vector <int> a(n * n, -1);
    for(int i = 0 ; i < n ; i++){
        a[b[i]] = i;
    }
    vector <int> found;
    vector <int> cnt(n);
    for(int i = 0 ; i < n * n ; i++){
        if(a[i] != -1){
            if(cnt[a[i]] != a[i]) finish("No");
            found.push_back(a[i]);
            cnt[a[i]]++;
            continue;
        }
        while(pt < n && cnt[p[pt]] >= p[pt]) pt++;
        while(found.size() && cnt[found.back()] == n) found.pop_back();
        if(pt < n) a[i] = p[pt];
        else if(found.size()) a[i] = found.back();
        else finish("No");
        cnt[a[i]]++;
    }
    cout << "Yes" << endl;
    for(auto &i : a) cout << i + 1 << " ";
    cout << endl;
}
