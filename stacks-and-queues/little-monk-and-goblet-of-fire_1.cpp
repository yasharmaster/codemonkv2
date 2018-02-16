#include <iostream>
#include <cstdio>
#include <climits>
#include <stack>
#include <queue>
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

void print_queue(queue<ll> q)
{
  while (!q.empty())
  {
    std::cout << q.front() << " ";
    q.pop();
  }
  cout << endl;
}

int main(){
	fast_io;
	if(fopen("tupni.txt", "r")) {
		freopen("tupni.txt", "r", stdin);
		freopen("tuptuo.txt", "w", stdout);
	}
	ll n, school, roll;
	cin>>n;
	string str;
	// Pair <School, Roll>
	queue<ll> **q1 = new queue<ll>*[5];
	FOR(i,1,4){
		q1[i] = new queue<ll>();
	}
	queue<ll> q;
	ll s, r;
	while(n--){
		cin>>str;
		if(str.compare("E")==0){
			cin>>s>>r;
			if(q1[s]->empty()){
				q.push(s);
			}
			q1[s]->push(r);
		}
		else if(str.compare("D")==0){
			s = q.front();
			r = q1[s]->front();
			cout<<s<<" "<<r<<endl;
			q1[s]->pop();
			if(q1[s]->empty()){
				q.pop();
			}
		}
	}
	return 0;
}