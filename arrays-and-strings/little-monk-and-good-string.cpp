#include <iostream>
#include <cstdio>
#include <climits>
#include <stack>
#include <vector>
#include <string>

#define LOG(x) cerr << "*** " << x << " ***" << endl;
#define wi(x) what_is(x, '\n')
#define wisp(x) what_is(x, ", ")
#define what_is(x, terminator) cerr << #x << " = " << x << terminator;

#define DBG false
#define endl "\n"
#define DEBUG(x) cout << '>' << #x << ':' << x << '\n';
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define mp make_pair
#define pb push_back
#define fast_io     ios_base::sync_with_stdio(0);cin.tie(NULL)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;

bool is_good(char ch) {
	bool verdict = false;
	switch (ch) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			verdict = true;
	}
	// cout << ch << " is " << verdict << endl;
	return verdict;
}

int max(int a, int b){
	return a>b?a:b;
}

int main(){
	fast_io;
	if(fopen("tupni.txt", "r")) {
		freopen("tupni.txt", "r", stdin);
		freopen("tuptuo.txt", "w", stdout);
	}
	string str;
	cin >> str;
	int n = str.size();

	vector<int> A(n+1, 0);
	A[0] = 0;
	int good_string_size = 0;
	FOR(i, 0, n-1){
		int index = i+1;
		if(is_good(str[i])){
			A[index] = A[index-1]+1;
		}
		else {
			A[index] = 0;
		}
		good_string_size = A[index]>good_string_size?A[index]:good_string_size;
	}

	cout << good_string_size;
	return 0;
}