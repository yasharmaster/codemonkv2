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

int main(){
	fast_io;
	if(fopen("tupni.txt", "r")) {
		freopen("tupni.txt", "r", stdin);
		freopen("tuptuo.txt", "w", stdout);
	}
	ll n,q,x,index=0, sum=0, popped, coins=0, ans = -1;
	cin>>n;
	ll A[n];
	REP(i,n){
		cin>>A[i];
	}
	cin>>q>>x;
	string str;
	stack<ll> monk;
	while(q--){
		cin>>str;
		if(str.compare("Harry")==0){
			monk.push(A[index]);
			if(DBG){
				wi(A[index]) LOG("pushed")
			}
			sum+=A[index++];
			coins++;
		} else {
			popped = monk.top();
			if(DBG){
				wi(popped) LOG("popped")
			}
			monk.pop();
			sum-=popped;
			coins--;
		}
		if(sum==x && ans==-1){
			ans = coins;
		}
	}
	cout<<ans;
	return 0;
}