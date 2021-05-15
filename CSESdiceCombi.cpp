#include<bits/stdc++.h>
#define int int64_t
#define pb emplace_back
#define mp make_pair
#define acc accumulate
#define f(n) for(int i=0;i<n;i++) 
#define f1(n) for(int i=1;i<n;i++) 
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef vector<int> vi;
const int mod = 1000000007;

int dp[1000002];
int solve(int n){

    if(n == 1 || n == 0) return 1;

    if(dp[n] != -1) return dp[n];

    int ans = 0;
    for(int i=1; i<=6; i++){
        if(i <= n){
            ans = (ans + solve(n-i))%mod;
        }
    }

    return dp[n] = ans;
}


int32_t main(){

	// freopen("input.txt", "r", stdin);

	// freopen("output.txt", "w", stdout);


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n; cin>>n;
    memset(dp, -1, sizeof dp);

    cout<<solve(n);


	return 0;
}