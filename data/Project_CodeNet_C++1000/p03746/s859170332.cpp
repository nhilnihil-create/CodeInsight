#include <bits/stdc++.h>

using namespace std;

    int a[100005];
    int b[100005];
    int bio[100005];
    vector<int> v[100001];
    deque<int> d;

int main (){

    int n,m;
    cin >> n >> m;

    for (int i = 0; i < m; i++){
        cin >> a[i] >> b[i];
        v[a[i]].push_back(b[i]);
        v[b[i]].push_back(a[i]);
    }

    bio[1] = 1;
    d.push_back(1);

    while (true){
        int e = 0;
        int prvi = d.front();
        for (int i = 0; i < v[prvi].size(); i++){
            if (bio[v[prvi][i]] == 0){
                d.push_front(v[prvi][i]);
                bio[v[prvi][i]] = 1;
                e = 1;
                break;
            }
        }
        int zadnji = d.back();
        for (int i = 0; i < v[zadnji].size(); i++){
            if (bio[v[zadnji][i]] == 0){
                d.push_back(v[zadnji][i]);
                bio[v[zadnji][i]] = 1;
                e = 1;
                break;
            }
        }
        if (e == 0)break;
    }

    cout << d.size() << "\n";

    for (int i = 0; i < d.size(); i++){
        cout << d[i] << " ";
    }

    return 0;
}
