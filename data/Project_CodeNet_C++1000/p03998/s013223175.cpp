#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    string sa, sb, sc;

    cin >> sa >> sb >> sc;


    char turn = 'a';
    //sa.erase(0, 1);
    char vic;
    while(1){
        if(turn == 'a'){
            if(sa.size() == 0){
                vic = 'a';
                break;
            }
            turn = sa[0];
            //printf("turn a discard %c\n", turn);
            sa.erase(0, 1);
        }
        else if(turn == 'b'){
            if(sb.size() == 0){
                vic = 'b';
                break;
            }
            turn = sb[0];
            //printf("turn b discard %c\n", turn);
            sb.erase(0, 1);
        }
        else if(turn == 'c'){
            if(sc.size() == 0){
                vic = 'c';
                break;
            }
            turn = sc[0];
            //printf("turn c discard %c\n", turn);
            sc.erase(0, 1);
        }
    }

    if(vic == 'a'){
        printf("A\n");
    }
    else if(vic == 'b'){
        printf("B\n");
    }
    else if(vic == 'c'){
        printf("C\n");
    }

    return 0;
}