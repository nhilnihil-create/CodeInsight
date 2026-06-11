#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <tuple>
#include <math.h>
#include <deque>
#include <stack>

using namespace std;

typedef long long ll;

struct Obj{
    ll w;
    ll v;
};

bool cmp(const Obj &a, const Obj &b){
    return a.v > b.v;
}


int main(void){
    ll n,W;
    cin >> n >> W;
    vector<Obj> objs(n);
    vector<Obj> w1;
    vector<Obj> w2;
    vector<Obj> w3;
    vector<Obj> w4;
    for(ll i = 0;i < n;i++){
        Obj obj;
        cin >> obj.w >> obj.v;
        objs[i] = obj;
        if(i != 0){
            if(obj.w == objs[0].w){
                w1.push_back(obj);
            }else if(obj.w == objs[0].w + 1){
                w2.push_back(obj);
            }else if(obj.w == objs[0].w + 2){
                w3.push_back(obj);
            }else if(obj.w == objs[0].w + 3){
                w4.push_back(obj);
            }
        }else{
            w1.push_back(obj);
        }
    }
    Obj obj;
    obj.w = 0;
    obj.v = 0;
    sort(w1.begin(), w1.end(), cmp);
    sort(w2.begin(), w2.end(), cmp);
    sort(w3.begin(), w3.end(), cmp);
    sort(w4.begin(), w4.end(), cmp);
    w1.insert(w1.begin(),obj);
    w2.insert(w2.begin(),obj);
    w3.insert(w3.begin(),obj);
    w4.insert(w4.begin(),obj);
    for(int i=1;i<w1.size();i++){
        w1[i].v += w1[i-1].v;
    }
    for(int i=1;i<w2.size();i++){
        w2[i].v += w2[i-1].v;
    }
    for(int i=1;i<w3.size();i++){
        w3[i].v += w3[i-1].v;
    }
    for(int i=1;i<w4.size();i++){
        w4[i].v += w4[i-1].v    ;
    }
    ll res = 0;
    for(int i = 0;i < w1.size();i++){
        for(int j = 0;j < w2.size();j++){
            for(int k = 0;k < w3.size();k++){
                for(int l = 0;l < w4.size();l++){
                    ll weight = i*objs[0].w + j*(objs[0].w + 1) + k*(objs[0].w + 2) + l*(objs[0].w + 3);
                    if(weight <= W){
                        ll sum = w1[i].v + w2[j].v + w3[k].v + w4[l].v;
                        res = max(res,sum);
                    }
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}
