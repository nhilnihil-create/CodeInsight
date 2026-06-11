/*
      author : nishi5451
      created: 12.08.2020 16:25:12
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    string sa,sb,sc;
    cin >> sa >> sb >> sc;
    int a = -1;
    int b = -1;
    int c = -1;
    a++;
    char no = sa[a];
    while(1){
        if(no=='a'){
            a++;
            if(a==sa.size()){
                cout << "A" << endl;
                return 0;
            }
            no = sa[a];
        }else if(no=='b'){
            b++;
            if(b==sb.size()){
                cout << "B" << endl;
                return 0;
            }
            no = sb[b];
        }else if(no=='c'){
            c++;
            if(c==sc.size()){
                cout << "C" << endl;
                return 0;
            }
            no = sc[c];
        }
    } 
    return 0;
}