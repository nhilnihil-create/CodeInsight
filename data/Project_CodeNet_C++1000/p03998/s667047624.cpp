#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    string sa, sb, sc; cin >> sa >> sb >> sc;
    int a = 0, b = 0, c = 0;

    char turn = 'a';
    while(1){
        //cout << turn << " ";
        
        if(turn == 'a'){
            if(a == sa.size()){
                cout << "A" << endl;
                return 0;
            }
            turn = sa[a];
            a++;
        }else if(turn == 'b'){
            if(b == sb.size()){
                cout << "B" << endl;
                return 0;
            }
            turn = sb[b];
            b++;
        }else if(turn == 'c'){
            if(c == sc.size()){
                cout << "C" << endl;
                return 0;
            }
            turn = sc[c];
            c++;
        }

    }

}