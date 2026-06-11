#include<iostream>
using namespace std;

void judgment(char me, char enemy, int &g_count, int &p_count, int &score);

int main(void){
    string s;
    cin >> s;
    int g_count = 0, p_count = 0, score = 0;
    char me;

    for(int i = 0; i < s.length(); ++i){
        me = p_count + 1 <= g_count ? 'p' : 'g';
        if(p_count + 1 > g_count) {
            me = 'g';
        }

        judgment(me, s.at(i), g_count, p_count, score);
    }

    cout << score << "\n";
    return 0;
}

void judgment(char me, char enemy, int &g_count, int &p_count, int &score){
    if(me == 'g') {
        g_count++;
        if(enemy == 'p') {
            score--;
        }
    } else {
        p_count++;
        if(enemy == 'g') {
            score++;
        }
    }
}