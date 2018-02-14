#include <iostream>
#include <cstdio>
#include <climits>
#include <stack>
#include <vector>
#include <algorithm>

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

typedef vector<ll> vi;

ll binary_search(ll *A, ll start, ll end, ll query){
	while(start<=end){
		ll mid = (end+start)>>1;
		if(A[mid]==query){
			return mid;
		} else if(A[mid]>query){
			end = mid-1;
		} else {
			start = mid+1;
		}
	}
	return -1;
}

int main(){
	fast_io;
	if(fopen("tupni.txt", "r")) {
		freopen("tupni.txt", "r", stdin);
		freopen("tuptuo.txt", "w", stdout);
	}
	ll n,q,query;
	cin>>n;
	ll A[n];
	REP(i,n){
	    cin>>A[i];
	}
	sort(A,A+n);
	cin >> q;
	while(q--){
		cin>>query;
		cout<<binary_search(A,0,n-1,query)+1<<endl;
	}
	return 0;
}