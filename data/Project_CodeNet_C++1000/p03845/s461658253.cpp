//#include<iostream>
//#include<algorithm>
//#include<string>
//#include <cmath>
//#include <vector>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(x,n) for(int x=0;x<n;x++)

//vector//
#define vei vector<int> 
#define velli vector<long long int> 
#define pb(x) push_back(x) // 末尾にxを加える
#define pb2 pop_back() // 末尾削除
#define all(x) (x).begin(),(x).end() //イテレーター
#define be(x) (x).begin()
//auto  auto begin = v.begin()とか

typedef pair<int,int> P;  //q(p.first,p.second)

int main (){
    int n;
    cin >> n;
    vector<int> t(n);
    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
    }
    int m;
    cin >> m;
    vector<pair<int,int>> x(m);
    for (int j = 0; j < m; j++)
    {   
        cin >> x[j].first >> x[j].second;
    }
    
    int sum_t = accumulate(all(t),0);

    for (int i = 0; i < m; i++)
    {
        int sa = x[i].second - t[x[i].first - 1];
        cout << sum_t + sa << endl;
    }
    
}