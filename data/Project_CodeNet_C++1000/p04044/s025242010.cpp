#include<iostream>
#include<algorithm>
using namespace std;

int comp_str(string s1, int pos, string s2) {
    int ret = 0;    // 0: s2の方が順序が小さい
    int size = s2.size();
    
    for ( int ii = 0; ii < size; ii++ ) {
        if ( s1[pos + ii] < s2[ii] ) {
            ret = 1;
            break;
        } else if ( s1[pos + ii] > s2[ii] ) {
            break;
        }
    }
    return ret;
}

int main() {
    int     N, L;
    string  s = "";
    string  tmp;
    int     ret;
    int     ii, jj;
    
    cin >> N >> L;
    
    for ( ii = 0; ii < N; ii++ ) {
        cin >> tmp;
        
        for ( jj = 0; jj < ii; jj++ ) {
            ret = comp_str(s, jj * L, tmp);
            if ( ret == 0 ) {
                s = s.insert(jj * L, tmp);
                break;
            }
        }
        if ( jj == ii ) {
            s.insert(s.size(), tmp);
        }
    }

    cout << s << endl;
    
    return 0;
}