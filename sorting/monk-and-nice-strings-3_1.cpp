#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string>

#define LOG(x) cerr << "*** " << x << " ***" << endl;

typedef long long ll;

#define DBG false
#define endl "\n"
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define fast_io     ios_base::sync_with_stdio(0);cin.tie(NULL)

using namespace std;

int main(){
    if(fopen("tupni.txt", "r")) {
        freopen("tupni.txt", "r", stdin);
        freopen("tuptuo.txt", "w", stdout);
    }
    ll n;
    cin>>n;
    string strs[n];
    REP(i,n){
        cin>>strs[i];
    }
    vector<int> niceness(n,0);
    niceness[0]=0;
    FOR(i,1,n-1){
        REP(j,i){
            if(strs[i]>strs[j]){
                niceness[i]++;
            }
        }
    }
    REP(i, n){
        cout<<niceness[i]<<endl;
    }
    return 0;
}