#include <bits/stdc++.h>
#include <algorithm>
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define VRSORT(v) sort(v.rbegin(), v.rend());
#define ll long long
#define pb(a) push_back(a)
#define INF 999999999
#define MOD (ll)(1e9+7)
#define MAX (ll)(1e5*2+200)
#define print(x) cout << x << endl;
#define length(arr) sizeof arr / sizeof arr[0];
#define printArr(arr) REP(i, (sizeof arr / sizeof arr[0])){print(arr[i])}
#define printVec(vec) REP(i, vec.size()){print(vec[i])}

using namespace std;

//右隣の動物の種類を返す関数
//x:左隣の動物の種類, y: 着目する位置の動物の種類
//S: sheap, W: walf
//ans = 'o' or 'x'
char Next(char ans, char x, char y){
    if(x == 'S' && y == 'S'){
       if(ans == 'o'){
            return 'S';
       }else{
            return 'W';           
       }
    }else if(x == 'W' && y == 'S'){
       if(ans == 'o'){
            return 'W';
       }else{
            return 'S';           
       }
    }else if(x == 'S' && y == 'W'){
       if(ans == 'o'){
            return 'W';
       }else{
            return 'S';           
       }
    }else if(x == 'W' && y == 'W'){
       if(ans == 'o'){
            return 'S';
       }else{
            return 'W';           
       }
    }
    return 'x';
}

string func(string s, char first, char last, char checkF, char checkL){
    char next;
    string ans = "";
    ans.push_back(first); 
    REP(i, s.size()){
        next = Next(s[i], last, first);
        if(i != s.size()-1){
            ans.push_back(next);
        }
        last = first;
        first = next;
    }
    if(first == checkF && last == checkL){
        return ans;
    }else{
        return "-1";
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    string s;
    cin >> N >> s;
    
    string ans;
    ans = func(s, 'S', 'S', 'S', 'S');
    if(ans != "-1"){
        print(ans);
        return 0;
    }
    
    ans = func(s, 'S', 'W', 'S', 'W');
    if(ans != "-1"){
        print(ans);
        return 0;
    }
    
    ans = func(s, 'W', 'S', 'W', 'S');
    if(ans != "-1"){
        print(ans);
        return 0;
    }
    
    ans = func(s, 'W', 'W', 'W', 'W');
    if(ans != "-1"){
        print(ans);
        return 0;
    }
    
    print("-1");
    return 0;
}
