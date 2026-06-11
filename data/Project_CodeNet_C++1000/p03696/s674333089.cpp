#include <iostream>
#include<string>
using namespace std;

int main()
{
    int N ;
    cin >> N ;
    string S ;
    cin >> S;
    string x ;
    int y = 0;
    for(int i =0 ; i<N ;i++){
        if(S[i]=='(')
            y++;
        else
            y--;
        if(y<0)
            x = '('+x ,y++;
        x+=S[i];
}
    while(y--)
        x+=')';
    cout << x;
    return 0;
}
