#include <iostream>
#include <string>
#include <vector>

using namespace std;

void check_all_paths (string & ss);
void check_simple (string & ss);

int main () {
    // paper (p) <= rock (g)
    string s;
    cin >> s;

    // check_all_paths(s);

    check_simple(s);

    return 0;
}

void check_simple (string & s) {
    int max_p = s.size()/2;
    int act_p = 0;
    for(int i = 0; i < s.size(); i++) {
        if (s[i] == 'p') act_p++;
    }
    cout << max_p - act_p << endl;
}


struct ss {
    bool g, p;
    int score;
};

void check_all_paths (string & s) {
    int gs = 0, ps = 0, i = 0, n=s.size();

    vector<ss> v(n);
    int score=0, max_score=-999999999;

    /*
      g 
     */
    while (i>=0) {
        if ( i == n ) {
            if (score > max_score)
                max_score=score;

//             cout << s << endl;
//             for(int x=0; x<n;x++) {
//                 cout << (v[x].p ? 'p' : 'g');
//             }
//             cout << " : " << gs << " - " << ps;
//             cout << endl;
//             for(int x=0; x<n;x++) {
//                 cout << (v[x].score < 0
//                          ? 'L' : (v[x].score == 0 ? 'D' : 'W'));
//             }

//             cout << " score = " << score
//                  << " (" << max_score << ")" << endl;

            i--;
        }

        char c = s[i];

        if (v[i].g == false) {
            gs++;
            if ( c == 'p' ) {
                score -= 1;
                v[i].score = -1;
            }
            v[i].g = true;
            i++;
            continue;
        } else if (v[i].p == false) {
            gs--;
            if (gs > ps) { // p 
                ps++;
                if ( c == 'g' ) {
                    score += 1;
                    v[i].score = +1;
                }
                v[i].p = true;
                i++;
                continue;
            }
        }        

        // both g & p tried
        if (v[i].p) ps--;
        v[i].g = v[i].p = false;
        score -= v[i].score;
        v[i].score = 0;
        i--;
        score -= v[i].score;
        v[i].score = 0;

    }

    cout << max_score << endl;
}
