#include<bits/stdc++.h> 
//#define <- プログラムの文字列を置換する
//typedef <- 新しい型に名前を付けるためのキーワード

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pair<int,int>,int> ppiii;

const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int INF_INT = 1e9;

template<class T> inline bool chmin(T& a, T b){
    if(a > b){
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmax(T& a, T b){
    if(a < b){
        a = b;
        return true;
    }
    return false;
}

template<class TYPE>
struct edge{
    TYPE to,cost; 
    edge(TYPE t,TYPE c){
        to = t;
        cost = c;
    }
};

int main(){
    string s;
    int sum = 0;
    cin >> s;
    vector<int> check(26);
    for(int i = 0; i < s.length(); i++){
        if(check[s[i] - 'a'] == 0){
            check[s[i] - 'a'] = 1;
            sum++;
        }
    }
    if(sum == 1){
        cout << 0 << endl;
        return 0;
    }
    ll cost = INF;
    for(int i = 0; i < 26; i++){
        if(check[i] == 0) continue;
        char C = 'a' + i;
        bool flg = true;
        string now = s;
        ll temp = 0;
        while(!flg || temp == 0){
            temp++;
            flg = true;
            string make = string();
            for(int j = 0; j < now.length() - 1; j++){
                if(now[j] == C || now[j+1] == C) make = make + C;
                else make = make + now[j];
            }
            for(int j = 0; j < make.length(); j++){
                if(make[j] != C) flg = false;
            }
            now = make;
        }
        cost = min(cost,temp);
    }
    cout << cost << endl;
    return 0;
}
