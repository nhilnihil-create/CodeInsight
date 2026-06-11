// ========================================================================================================
// Library
// ========================================================================================================
#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
using namespace std;

// competitive macro
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (b) - 1; i >= (a); i--)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define RREP(i ,n) for (int i = (n) - 1; i >= 0; i--)
#define LL long long
#define ULL unsigned long long

void fastIOS()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
}
// ========================================================================================================
// ========================================================================================================

int main()
{
	fastIOS();

	string s; cin >> s;
    
    int index = 0 , c = 0;
    char x = s[0];
    int i = 0;
    
    if(s.size()==2 && s[0] == s[1]){
        cout<< 1 << " " << 2;
        return 0;
    }
    if(s.size()>=2){
        while(i<s.size()){
//            printf("First : i = %d\tindex = %d\tc = %d\tx = %c\n" , i , index,c,x);

            if(s[i]==x){
                c++;
            }
            else{
                c--;
            }

            if(c<0)
            {
                c = 1;
                i--;
                x = s[i];
                index = i;
            }
            
            if(i-index>=2){
                cout << index+1 << " " << i+1 << endl;
                return 0;
            }
            
            i++;
            
//            printf("Last : i = %d\tindex = %d\tc = %d\tx = %c\n" , i , index,c,x);
        }
    }
    
    cout << -1 << " " << -1 << endl;
    
    return 0;
}