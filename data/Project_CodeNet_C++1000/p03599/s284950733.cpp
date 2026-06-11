#include<bits/stdc++.h> 
//#define <- プログラムの文字列を置換する
//typedef <- 新しい型に名前を付けるためのキーワード

using namespace std;

#define MAX_N 100000

typedef long long ll;
typedef pair<int,int> P;

const long long MOD = 1e9 + 7;
const long long INF = 1e15;
const int INF_INT = 1e9;

template<class TYPE>
struct edge{
    TYPE to,cost; 
    edge(TYPE t,TYPE c){
        to = t;
        cost = c;
    }
};

int main(){
    int A,B,C,D,E,F;
    cin >> A >> B >> C >> D >> E >> F;
    vector<int> water;
    vector<int> sugar;
    int check[3001];
    priority_queue<int,vector<int>,greater<int>> q;
    q.push(100*A);
    q.push(100*B);
    check[100*A] = check[100*B] = 1;
    while(!q.empty()){
        int m = q.top();
        q.pop();
        water.emplace_back(m);
        if(m + 100*A <= F && check[m + 100 * A] == 0){
            q.push(m+100*A);
            check[m + 100 * A] == 1;
        }
        if(m + 100*B <= F && check[m + 100 * B] == 0){
            q.push(m+100*B);
            check[m + 100 * B] == 1;
        }
    }
    memset(check,0,sizeof check);
    q.push(0);
    q.push(C);
    q.push(D);
    check[0] = check[C] = check[D] = 1;
    while(!q.empty()){
        int s = q.top();
        q.pop();
        sugar.emplace_back(s);
        if(s + C <= F && check[s + C] == 0) {
            q.push(s+C);
            check[s + C] = 1;
        }
        if(s + D <= F && check[s + D] == 0) {
            q.push(s+D);
            check[s + D] = 1;
        }
    }
    int n = sugar.size();
    double maxi = -1;
    int ans_water;
    int ans_sugar;
    for(int w : water){
        int left = 0;
        int right = n;
        while(right - left > 1){
            int mid = (left + right) / 2;
            if(w + sugar[mid] > F) right = mid;
            else if(w / 100 * E >= sugar[mid]) left = mid;
            else right = mid;
        }
        double temp = (double)100 * sugar[left] / (w + sugar[left]);
        if(maxi < temp){
            maxi = temp;
            ans_water = w;
            ans_sugar = sugar[left];
        } 
    }
    cout << ans_water+ans_sugar << " " << ans_sugar << endl;
    return 0;
}
