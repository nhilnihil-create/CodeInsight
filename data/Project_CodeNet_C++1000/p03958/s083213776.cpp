#include<iostream>
#include<queue>
#include<string>// 加法 S.size() s.substr(l,r=s.size()-l) -> l文字目からr文字分
#include<cmath>//三角関数,rad
#include<algorithm>　//__gcd()　lower_bound(a+l,a+r,x)-a でindex
// vector -> min/max({vector}) 
// 配列   -> *min_element(a+l,a+r)  *忘れず lとrで[l,r) 
//reverse(a+l,a+r)   配列aの[l,r)を逆順に strはreverse(S.begin(),S.end())
//sort(a+l,a+r,greater <int>()) 配列aの[l,r)昇順sort,大きい順はgreater<type>()
//vectorならv.begin(),v.end()
#include<ctime>//"clock()/CLOCKS_PER_SEC で秒数
#include<vector>//v.push_back(x),v.pop_back()
#include<queue>//q.push(x),front()で先頭を返す,pop()で削除, size(),empty()
#include<functional>//vector,queueと併用でpriority_queue
//宣言は priority_queue< Type, vector<Type>, greater<Type>> Q1; 
// pq.push(x),top()で参照 pop()で削除   greaterで最小 lessで最大がtopに
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
int main(){
    int k,t,d;d=-1;cin>>k>>t;int v[t];rep(i,t){int y;cin>>y;if(y>k/2){d=y;}v[i]=y;}
    if (d!=-1){cout<<2*d-k-1<<endl;}else{cout<<0<<endl;}
}