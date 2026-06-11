#include<bits/stdc++.h>
using namespace std;
using i64 = int_fast64_t;
#define rep(i, N) for(int (i) = 0; (i) < (N); (i)++)
#define all(v) (v).begin(), (v).end()
#define eb emplace_back

int main(){
    int N;
    cin >> N;
    map<int,int> cards;
    rep(i ,N){
        int A; cin >> A;
        cards[A]++;
    }

    int even = 0;
    for(auto& card : cards) {
        if(card.second > 2) card.second = 1 + ((card.second-3) % 2);
        if(card.second == 2) even++;
    }
    
    int kind = cards.size();
    if(even%2) cout << kind - 1 << endl;
    else cout << kind << endl;
}