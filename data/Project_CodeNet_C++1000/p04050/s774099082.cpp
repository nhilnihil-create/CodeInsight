#include <cstring>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
const int N = 110;
int _w;

int n, m;
vector<int> odd, even;

int main() {
	cin >> m >> n;
	for( int i = 1; i <= n; ++i ) {
		int a;
		cin >> a;
		if( a & 1 ) odd.push_back(a);
		else even.push_back(a);
	}
	if( odd.size() > 2 )
		return puts("Impossible"), 0;
	if( odd.size() == 0 ) {
		for( int i = 0; i < (int)even.size(); ++i )
			printf( "%d ", even[i] );
		puts("");
		if( even.size() == 1 ) {
			int a = even[0];
			puts("2");
			printf( "%d %d\n", a-1, 1 );
		} else {
			printf( "%d\n", (int)even.size() );
			printf( "%d ", even[0]+1 );
			for( int i = 1; i < (int)even.size()-1; ++i )
				printf( "%d ", even[i] );
			printf( "%d\n", *even.rbegin()-1 );
		}
	} else if( odd.size() == 1 ) {
		for( int i = 0; i < (int)even.size(); ++i )
			printf( "%d ", even[i] );
		printf( "%d\n", odd[0] );
		if( even.size() ) {
			printf( "%d\n", odd[0] == 1 ? n-1 : n );
			printf( "%d ", even[0]+1 );
			for( int i = 1; i < (int)even.size(); ++i )
				printf( "%d ", even[i] );
			if( odd[0] != 1 )
				printf( "%d\n", odd[0]-1 );
		} else {
			int a = odd[0];
			if( a != 1 ) {
				puts("2");
				printf( "%d %d\n", a-1, 1 );
			} else {
				puts("1"), puts("1");
			}
		}
	} else {
		printf( "%d ", odd[0] );
		for( int i = 0; i < (int)even.size(); ++i )
			printf( "%d ", even[i] );
		printf( "%d\n", odd[1] );
		printf( "%d\n", odd[1] == 1 ? n-1 : n );
		printf( "%d ", odd[0]+1 );
		for( int i = 0; i < (int)even.size(); ++i )
			printf( "%d ", even[i] );
		if( odd[1] != 1 )
			printf( "%d\n", odd[1]-1 );
	}
	return 0;
}
