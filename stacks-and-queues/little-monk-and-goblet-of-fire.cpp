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
	deque<pair<ll,ll> > myqueue;
	stack<pair<ll,ll> > temp_stack;
	while(n--){
		cin>>str;
		if(str.compare("E")==0){
			cin>>school>>roll;
			if(DBG){
				
			}	
			if(myqueue.empty()){
				if(DBG){
					wi(school) wi(roll) LOG("inserted")
				}
				myqueue.push_back(make_pair(school,roll));
			}
			else {
				pair<ll,ll> last_element = myqueue.back();
				while(last_element.first!=school){
					myqueue.pop_back();
					if(DBG){
						wi(last_element.first) wi(last_element.second) LOG("popped")
					}
					temp_stack.push(last_element);
					if(myqueue.empty()){
						break;
					}
					last_element = myqueue.back();
				}
				if(myqueue.empty()){
					while(!temp_stack.empty()){
						last_element = temp_stack.top();
						myqueue.push_back(last_element);
						if(DBG){
							wi(last_element.first) wi(last_element.second) LOG("popped")
						}
						temp_stack.pop();
					}
					myqueue.push_back(make_pair(school,roll));
				}
				else{
					myqueue.push_back(make_pair(school,roll));
					while(!temp_stack.empty()){
						last_element = temp_stack.top();
						myqueue.push_back(last_element);
						if(DBG){
							wi(last_element.first) wi(last_element.second) LOG("popped")
						}
						temp_stack.pop();
					}
				}
				if(DBG){
					wi(school) wi(roll) LOG("inserted")
				}
			}
		}
		else if(str.compare("D")==0){
			pair<ll,ll> student = myqueue.front();
			myqueue.pop_front();
			cout<< student.first << " " << student.second << endl;
		}
	}
	return 0;
}