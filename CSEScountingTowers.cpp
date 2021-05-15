#include<bits/stdc++.h>
#define int int64_t
#define pb emplace_back
#define mp make_pair
#define acc accumulate
#define f(n) for(int i=0;i<n;i++) 
#define f1(n) for(int i=1;i<n;i++) 
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000007
using namespace std;
typedef vector<int> vi;
const int mod = 1e9 + 7;
 
int n = 1000000;
int dp[1000002][2];


int32_t main(){

	// freopen("input.txt", "r", stdin);

	// freopen("output.txt", "w", stdout);


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    dp[n+1][0] = dp[n+1][1] = 1;

    for(int i=n; i>=2; i--){

        int op1 = (dp[i+1][0] + dp[i+1][1])%mod;
        int op2 = dp[i+1][0];
        int op3 = (2*(dp[i+1][0]))%mod;
        int op4 = dp[i+1][1];

        dp[i][0] = (op1 + op2 + op3)%mod;
        dp[i][1] = (op1 + op4)%mod;

    } 

    int q; cin>>q;

    while(q--){

        int query; cin>>query;

        cout << (dp[n-query+2][1] + dp[n-query+2][0])%mod <<"\n";

    }

    return 0;
}