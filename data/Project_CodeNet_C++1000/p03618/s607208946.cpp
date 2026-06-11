#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
///1<<3シフト演算子 とは　0001の1を三つずらして1000にする, これは8を表しておりつまりbitは0から7まで
#define all(x) (x).begin(),(x).end()
#define cyes cout<<"Yes"<<endl
#define cno cout<<"No"<<endl
#define sp <<" "<<
#define CST(x) cout<<fixed<<setprecision(x)
#define PI 3.14159265359
using namespace std;
using ll = long long;
using ld = long double;

//条件式 ? 真の場合の文 : 偽の場合の文
//abs(x) = (x の絶対値)
//string S  S,at(i),S += T,S += c,S.size(),S.substr(l)l文字目から最後まで,
///S.substr(l, r)l文字目からl+r-1文字目 n文字目から0個で空列を返せる
//*min_element(all(x)) *max_element(all(x))
//vi x; x.back(),x.front(),x.push_back(),x.pop_back()
//swap(a, b)
//gcd(a, b)最大公約数
//sort(all(x)),reverse(all(x)),sort(x.begin()+l,a.begin()+r)lからrまで
//stack<int> a; a.push(x),a.pop(),a.top(),a.empty()bool
//queue<int> b; b.push(x),b.pop(),b.front(),b.empty()bool,b.size() 要素が小さい順
//priority_queue<int, vector<int>, greater<int>> c,c.top()
//map<int, int> M1; 変数[key] = value; 変数.erase(key); 変数.at(key); 変数.count(key)所属判定　変数.size()
//find(all(x), key)boolソート済みのベクトル
//*lower_bound(all(x),k)以上の最小の要素,*uppper_bound(all(x),k)より大きい最小の要素
//char('0'+cnt) 数字cntからcharへの変換
//int(char-'0') charからintへの変換


int main(){
    
    string s;
    cin >> s;
    map<char,ll> ma;
    int len = s.size();
    rep(i,len){
        ma[s.at(i)]++;
    }
    ll cnt = 0;
    for(char ch = 'a'; ch <= char('z'-1); ch++){
        for(char cha = char(ch+1); cha <= 'z'; cha++){
            cnt += ma[ch]*ma[cha];
        }
    }
    
    cout << cnt + 1 << endl;


}
