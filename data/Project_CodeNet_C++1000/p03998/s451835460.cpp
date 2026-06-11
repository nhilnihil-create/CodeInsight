#include <bits/stdc++.h>

using namespace std;




int main(void)
{
   string A,B,C;
   char isTurn='a',ans;
   queue<char> a,b,c;

   cin>>A>>B>>C;

    for(int i=0;i<A.size();i++){
        a.push(A[i]);
    }
        for(int i=0;i<B.size();i++){
        b.push(B[i]);
    }
        for(int i=0;i<C.size();i++){
        c.push(C[i]);
    }

    bool isEnd=false;
    while(!isEnd){
        switch (isTurn)
        {
        case 'a'/* constant-expression */:
            /* code */
            if(a.size() <= 0){
                ans='A';
                isEnd=true;
            }
            isTurn = a.front();
            a.pop();
            break;
        case 'b':
            if(b.size() <= 0){
                ans='B';
                isEnd=true;
            }
            isTurn = b.front();
            b.pop();
            break;
        case 'c':
            if(c.size() <= 0){
                ans='C';
                isEnd=true;
            }
            isTurn = c.front();
            c.pop();
            break;
        
        default:
            break;
        }
    }

    cout<<ans<<endl;


 
	return 0;
}
