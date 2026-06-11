#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100000;
int n , j , a[ MAXN + 5 ];

bool cmp( const int &x , const int &y ) {
	return x > y;
}

int main( ) {
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i ++ )
		scanf("%d",&a[ i ]);
	sort( a + 1 , a + n + 1 , cmp );
	
	for( int i = 1 ; i <= n ; i ++ )
		if( i + 1 > a[ i + 1 ] ) {
			for( j = 0 ; a[ j + i + 1 ] == i ; j ++ );
			puts( ( ( a[ i ] - i ) & 1 || ( j & 1 ) ) ? "First" : "Second" );
			break;
		}
	return 0;
}