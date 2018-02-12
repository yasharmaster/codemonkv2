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
typedef vector<vector<ll> > vvi;

ll height_diff(ll *A, ll n, ll max, ll min){
	if(min >= max){
		return -1;
	}
	vector<ll> freq(max-min+1,0);
	REP(i,n){
		freq[A[i]-min]++;
	}
	ll max_freq = INT_MIN, min_freq = INT_MAX;
	REP(i,max-min+1){
		if(freq[i]>0){
			if(freq[i]>max_freq){
				max_freq = freq[i];
			}
			if(freq[i]<min_freq){
				min_freq = freq[i];
			}			
		}
	}
	return max_freq-min_freq;
}

int main(){
	fast_io;
	if(fopen("tupni.txt", "r")) {
		freopen("tupni.txt", "r", stdin);
		freopen("tuptuo.txt", "w", stdout);
	}
	ll t;
	cin >> t;
	while (t--) {
	    ll n;
	    cin >> n;
	    ll A[n];
	    ll max = INT_MIN, min = INT_MAX;
	    REP(i,n){
	    	cin>>A[i];
	    	if(A[i]>max){
	    		max = A[i];
	    	}
	    	if(A[i]<min){
	    		min = A[i];
	    	}
	    }
	    cout<<height_diff(A,n,max,min)<<endl;
	}
	return 0;
}