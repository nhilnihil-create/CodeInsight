#include<bits/stdc++.h>
using namespace std;

int main(){
    int k, t;
    cin >> k >> t;

    int a[t];
    priority_queue<pair<int, int> > q;
    for(int i = 0; i < t; i++){
        cin >> a[i];
        q.push(make_pair(a[i], i));
    }

    int cou = 0;
    int flag = -1;
    while(!q.empty()){
        pair<int, int> l = q.top();
        q.pop();
        if(flag != l.second){
            flag = l.second;
            l.first--;
            if(l.first != 0){
                q.push(l);
            }
        }else{
            if(q.empty()){
                cou += l.first;
            }else{
                pair<int, int> m = q.top();
                q.pop();
                flag = m.second;
                m.first--;
                q.push(l);
                if(m.first != 0){
                    q.push(m);
                }
            }
        }
    }

    cout << cou << endl;

}