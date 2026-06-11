#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#define ll long long

using namespace std;

long long MOD = 1000000007;

struct cake{
    int num, kind;
};

bool operator< (const cake &cake1, const cake &cake2){
    return cake1.num<cake2.num;
}
bool operator> (const cake &cake1, const cake &cake2){
    return cake1.num>cake2.num;
}


int main(){
    int K, T;
    cin >> K >> T;
    priority_queue<cake, vector<cake>, less<cake>> pque;
    for(int i=0; i<T; i++){
        int a;
        cin >> a;
        pque.push({a,i});
    }
    pque.push({0,-1});

    int ans=0;
    int prev=-1;
    for(int i=0; i<K; i++){
        cake tmp=pque.top();
        pque.pop();

        if(prev!=tmp.kind){
            tmp.num--;
            prev=tmp.kind;
        }else{
            if(pque.top().num==0){
                tmp.num--;
                ans++;
            }else{
                cake tmp2=pque.top();
                pque.pop();
                tmp2.num--;
                pque.push(tmp2);
                prev=tmp2.kind;
            }
        }
        pque.push(tmp);
        //cout << prev << endl;
    }
    cout << ans << endl;
}