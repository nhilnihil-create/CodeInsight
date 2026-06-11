#include <bits/stdc++.h>
using namespace std;

int N, L, T;
//a 時計回り
//b 逆時計回り
int main() {
    cin >> N >> L >> T;
    vector<int> a(N), b(N);
    int ac = 0;
    int bc = 0;
    int ai0 = 0;
    int av0 = 0;
    int ab0 = 0;

    for (int i = 0; i < N; i ++){
        int ci, wi;
        cin >> ci >> wi;
        if (wi == 1) {
            if (ac == 0){
                ai0 = i;
                av0 = ci;
                ab0 = bc;
            }
            a[ac] = ci;
            ac++;
        }else{
            b[bc] = ci;
            bc++;
        }
    }

    int dt =  T % L;
    //例外処理
    if (bc == 0) {
        for(int i = 0; i < N; i++){
            int p = (a.at(i) + dt) % L;
            cout << p << endl;
        }
        return 0;
    }
    if (ac == 0) {
        for(int i = 0; i < N; i++){
            int p = (L + b.at(i) - dt) % L;
            cout << p << endl;
        }
        return 0;
    }

    // (T % L)秒で何個の反時計周り出会うかの計算
    int count = ai0 + (T / L) * bc * 2;
    int dt2 = dt * 2 ;
    if (dt2 >= L){
        count += bc;
        dt2 -= L;
    }
    int pb;
    if ((av0 + dt2) > L){
        auto iter = lower_bound(b.begin(), b.begin() + bc, av0 + dt2 - L);
        pb = distance(b.begin(), iter);
        count += bc + pb - ab0;
    }
    else{
        auto iter = lower_bound(b.begin(), b.begin() + bc, av0 + dt2);
        pb = distance(b.begin(), iter);
        count += pb - ab0;
    }

    pb = pb % bc;
    int av = (a.at(0) + dt) % L;
    int bv = (L + b.at(pb) - dt) % L;
    int pa = 0;
    int base = av;
    if (bv < base)
        bv += L;
    int acount = 0;
    int bcount = 0;
    count = count % N;
    bool flag = count == 0;
    queue<int> que;
    while(acount < ac && bcount < bc){
        if (av <= bv){
            if(flag)
                cout << av % L << endl;
            else
                que.push(av % L);
            pa++;
            if (pa == ac){
                pa = 0;
            }
            av = (a.at(pa) + dt) % L;
            if (av < base)
                av += L;
            acount++;
        }
        else{
            if(flag)
                cout << bv % L << endl;
            else
                que.push(bv % L);
            pb++;
            if (pb == bc){
                pb = 0;
            }
            bv = (L + b.at(pb) - dt) % L;
            if (bv < base)
                bv += L;
            bcount++;
        }
        count++;
        if (count == N)
            flag = true;
    }
    av %= L;
    for(int i = acount; i < ac; i++){
        if(flag)
            cout << av % L << endl;
        else
            que.push(av);
        pa++;
        if (pa == ac){
            pa = 0;
        }
        av =  (a.at(pa) + dt) % L;
        count++;
        if (count == N)
            flag = true;
    }
    bv %=  L;
    for(int i = bcount; i < bc; i++){
        if (flag)
            cout << bv << endl;
        else
            que.push(bv);
        pb++;
        if (pb == bc){
            pb = 0;
        }
        bv =  (L + b.at(pb) - dt) % L;
        count++;
        if (count == N)
            flag = true;
    }
    while(!que.empty()) {
        cout << que.front() << endl;
        que.pop();
    }
}