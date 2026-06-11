# include <iostream>
# include <string>
# include <algorithm>
# include <vector>
# include <cstring>
# include <stdio.h>
# include <map>
# include <queue>

# define ll long long
# define pii pair<int,int>
# define FOR(a,b) for(int a=1; a<=b; a++)
# define REP(a,b) for(int a=0; a<b; a++)
# define FORU(a,b,c) for(int a=b; a<=c; a++)
# define FORD(a,b,c) for(int a=b; a>=c; a--)

using namespace std;

int candy[100005];
int main(){

    ios :: sync_with_stdio(false);
    int N;
    cin >> N;

    FOR(i,N) cin >> candy[i];
    sort(candy+1, candy+1+N);

    int cur = 0;
    FORD(i,N,1){
        cur++;
        if(cur >= candy[i-1]){
            if((candy[i]-cur)&1){
                cout << "First" << endl;
            }
            else{
                FORD(j,i,0){
                    if(cur >= candy[j-1]+1){
                        if((j-i)&1){
                            cout << "First" << endl;
                        }
                        else cout << "Second" << endl;
                        break;
                    }
                }
            }
            break;
        }
    }

    return 0;
}