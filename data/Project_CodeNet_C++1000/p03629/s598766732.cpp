#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<algorithm>
#define maxn 200005
using namespace std;
int L[maxn], R[maxn], ans;
int ch[30];
char s[maxn];

int main() {    
    scanf( "%s", s );
    int len = strlen( s );
    int now = 26;
    R[0] = len - 1;
    for( int i = len - 1; i >= 0; i -- ) {
        if( !ch[s[i] - 'a'] ) {
            now --;
            ch[s[i] - 'a'] = 1;
            if( !now ) {
                L[ans] = i;
                ans ++;
                R[ans] = i - 1;
                now = 26;
                memset( ch, 0, sizeof( ch ) );
            }
        }
    }
    L[ans] = 0;
    int l = 0;
    char now_ans;
    for( int i = ans; i >= 0; i -- ) {
        int now = 26;
        memset( ch, 0, sizeof( ch ) );
        for( int j = l; j <= R[i]; j ++ ) {
        	ch[s[j] - 'a'] = 1;
		}
        for( int j = 0; j < 26; j ++ ) {
        	if( !ch[j] ) {
            	printf( "%c", j + 'a' );
            	now_ans = j + 'a';
            	break;
        	}
		}
        for( int j = l; j < len; j ++ ) {
        	if( s[j] == now_ans ) {
            	l = j + 1;
            	break;
        	}
		}
    }
}