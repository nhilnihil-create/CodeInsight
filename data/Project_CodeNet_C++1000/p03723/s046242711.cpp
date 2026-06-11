#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<queue>
using namespace std;
#define rep(i, n) for (int i=0; i<(int) (n);i++)
using ll = long long;
using P = pair<int,int>;

void solve_8(){//7m
    string a, b;
    cin >> a >> b;
    string tmp =  a+b;
    int c = atoi(tmp.c_str());
    //cout << c << endl;
    int c_square = sqrt(c);
    cout << (c_square * c_square == c? "Yes": "No") << endl;
    
}

void solve_8re(){
    string a, b;
    cin >> a >> b;
    //stoi -> int
    //stol -> long
    //stof -> float
    int c = stoi(a+b);
    int c_square = sqrt(c);
    cout << (c_square * c_square == c? "Yes": "No")<< endl;
}

void solve_9(){//12m
    int n,k;
    cin >> n >> k;
    int sum_distance = 0;
    rep(i, n){
        int x;
        cin >> x;
        sum_distance += 2 * min(x, k-x);
    }
    cout << sum_distance;
}

void solve_10(){//7m
    int n;
    cin >> n;
    priority_queue<int> pq;
    int a;
    rep(i, n){
        cin >> a;
        pq.push(a);
    }
    int alice = 0, bob = 0;
    int turn = 0;
    while(!pq.empty()){
        a = pq.top();
        pq.pop();
        if (turn % 2 == 0){
            alice += a;
        }
        else{
            bob += a;
        }
        turn += 1;
    }
    cout << alice - bob;
    
}
#include<algorithm>
void solve_10re(){
    int n;
    cin >> n;
    vector<int> a;
    int a_;
    rep(i, n){
        cin >> a_;
        a.push_back(a_);
    }
    sort(a.begin(), a.end(), greater<int>());
    int total = 0;
    rep(i, n){
        total += (i%2==0?a[i]:-a[i]);
    }
    cout << total;
}

void solve_11(){//7m
    int n;
    cin >> n;
    int score;
    rep(i,7){
        if (n >= pow(2, i))
        {
            score = pow(2,i);
        }
    }
    cout << score;
}

void solve_12(){
    int a, b, c;
    cin >> a >> b >> c;
    int count = 0;
    int tmp_a, tmp_b, tmp_c;
    while(a%2==0 && b%2==0 && c%2==0){
        if (a==b && b == c && c == a)
        {
            count = -1;
            break;
        }
        
        tmp_a = b/2 + c/2;
        tmp_b = a/2 + c/2;
        tmp_c = a/2 + b/2;
        a = tmp_a;
        b = tmp_b;
        c = tmp_c;
        count++;
    }
    cout << count << endl;

}

void solve_F(){
    
}

int main(){
    //solve_8re();
    //solve_9();
    //solve_10re();
    solve_12();
    //solve_E();
    //solve_F();
    return 0;
}