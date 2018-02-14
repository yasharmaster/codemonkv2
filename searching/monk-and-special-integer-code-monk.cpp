#include <iostream>
#include <cstdio>
#include <cmath>
#include <climits>
#include <algorithm>
#include <string>

#define LOG(x) cerr << "*** " << x << " ***" << endl;
#define wi(x) what_is(x, '\n')
#define wisp(x) what_is(x, ", ")
#define what_is(x, terminator) cerr << #x << " = " << x << terminator;

typedef long long ll;

#define DBG false
#define endl "\n"
#define DEBUG(x) cout << '>' << #x << ':' << x << '\n';
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define mp make_pair
#define pb push_back
#define fast_io     ios_base::sync_with_stdio(0);cin.tie(NULL)

using namespace std;

int main(){
	fast_io;
	if(fopen("tupni.txt", "r")) {
		freopen("tupni.txt", "r", stdin);
		freopen("tuptuo.txt", "w", stdout);
	}
	ll n,x;
	cin>>n>>x;
	ll A[n+1], B[n+1];
	FOR(i,1,n){
		cin>>A[i];
	}
	B[0]=A[0]=0;
	FOR(i,1,n){
		B[i] = B[i-1]+A[i];
	}
	ll min_window = n;
	FOR(i,1,n){
		ll ub = (ll)(upper_bound(B+i, B+n, B[i-1]+x)-B);
		if(DBG){
			wi(ub)			
		}
		if(ub==n && B[ub]<=B[i-1]+x){
			break;
		}
		ll window = ub-i;
		if(DBG){
			wi(window)			
		}
		min_window = min(window,min_window);
	}
	cout<<min_window;
	return 0;
}