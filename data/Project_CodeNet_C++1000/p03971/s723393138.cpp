#include <bits/stdc++.h>
//#define DEBUG
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
template <class T>
void print_vect(std::vector<T> v){
    for(int i = 0 ; i < v .size(); i++) cout << v[i] << " ";
    cout << endl;
}

void solve(){
    int n, a, b;
    string S;
    cin >> n >> a >> b;
    cin >> S;
    int count_japanese = 0;
    int count_foreigner = 0;
    int i;
    for(i = 0 ; i < S.size() && count_foreigner + count_japanese < a + b ; i++){
        if( S[i] == 'a'){
            cout << "Yes\n";
            count_japanese++;
        }else if(S[i] == 'b'){
            if(count_foreigner < b){
                cout << "Yes\n";
                count_foreigner++;
            }else{
                cout << "No\n";
            }
        }else{
            cout << "No\n";
        }
    }
    for(; i < S.size() ; i++){
        cout << "No\n";
    }
}

int main()
{
    //making data IO Fast
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    /****************************/

    #ifdef DEBUG
    int TEST_CASES = 2;
    while(TEST_CASES--){
    #endif // DEBBUG

    solve();

    #ifdef DEBUG
    }
    #endif // DEBUG
    
    return 0;
}

