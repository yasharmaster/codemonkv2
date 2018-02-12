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
    string strs[n], sorted[n];
    REP(i,n){
        cin>>strs[i];
        sorted[i]=strs[i];
    }
    sort(sorted, sorted+n);
    vector<ll> rank(n, -1);
    ll number=0;
    REP(i, n){
        string str = sorted[i];
        REP(j,n){
            if(rank[j]==-1 && strs[j]==str){
                rank[j]=number;
            }
        }
        number++;
    }
    vector<int> niceness(n);
    REP(i,n){
        int count=0;
        REP(j,i){
            if(rank[j]<rank[i])
                count++;
        }
        niceness[i]=count;
    }
    REP(i, n){
        cout<<niceness[i]<<endl;
    }
    return 0;
}