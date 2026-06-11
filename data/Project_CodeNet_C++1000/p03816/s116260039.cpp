#include <bits/stdc++.h>

using namespace std;

int main (void) {
    int N;
    cin >> N;
    map<int, int> card;
    for ( int i = 0; i < N; i++ ) {
        int a;
        cin >> a;
        card[a]++;
    }

    int left_one = 0, left_two = 0;
    for ( auto cur = card.begin(); cur != card.end(); cur++ ) {
        int n_card = cur->second;

        /* 同じ数のカードを3枚選ぶことで2枚ずつ減らせる
         * 偶数枚なら最後に必ず2枚残り、奇数枚なら1枚残る */
        if ( n_card % 2 == 0 ) left_two++;
        else left_one++;
    }

    /* 2枚残っているカードが偶数組あれば、それらをすべて1枚にできる
     * 奇数組ならば left_one から 1組犠牲にする */
    int ans;
    if ( left_two % 2 == 0 ) ans = left_one + left_two;
    else ans = left_one + left_two - 1;

    cout << ans << endl;
    return 0;
}
