#include<bits/stdc++.h>
using namespace std;

int main(){
    string sa, sb, sc; cin >> sa >> sb >> sc;
    int a_id=0, b_id=0, c_id=0;

    int order = 0; // 0:a 1:b 2:c
    while(true){
        int tmp =0;
        if(order==0){
            if(a_id == sa.length()){
                cout << 'A' << endl;
                break;
            }
            tmp = sa[a_id] - 'a';
            
            a_id++;
        }else if(order==1){
            if(b_id == sb.length()){
                cout << 'B' << endl;
                break;
            }
            tmp = sb[b_id] - 'a';
            b_id++;
        }else if(order==2){
            if(c_id == sc.length()){
                cout << 'C' << endl;
                break;
            }
            tmp = sc[c_id] - 'a';
            c_id++;
        }
        order = tmp;
    }
    return 0;
}