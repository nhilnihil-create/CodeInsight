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

int main(){
    int N;
    cin >> N;
    vector<ll> ans(N+1,0);
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,less<pair<ll,int>>> que;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        que.push(make_pair(a,-i-1));
    }
    que.push(make_pair(0,0));

    priority_queue<pair<ll,int>,vector<pair<ll,int>>,less<pair<ll,int>>> tmp;
    ll a=que.top().first;
    int pos=-que.top().second;
    ll cnt=1;
    que.pop();
    while((int)que.size()){
        ll b=que.top().first;
        int sec=-que.top().second;
        que.pop();
        //cout << a << ' ' << pos << ' ' << b << ' ' << sec << ' ' << cnt << endl;
        if(pos>sec){
            //cout << pos << ' ' << sec << ' ' << cnt << endl;
            ans[pos]=cnt*(a-b);
            while((int)tmp.size()&&tmp.top().first>=b){
                //cout << "tmp " <<  tmp.top().first << ' ' << tmp.top().second << endl;
                ans[pos]+=tmp.top().first-b;
                cnt++;
                tmp.pop();
            }
            cnt++;
            a=b;
            pos=sec;
        }else{
            tmp.push(make_pair(b,-sec));
        }
    }
    for(int i=1; i<=N; i++){
        cout << ans[i] << '\n';
    }
}