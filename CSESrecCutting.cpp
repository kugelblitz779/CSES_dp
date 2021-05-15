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
 
int dp[502][502];
int solve(int i, int j){
    
    if(i == j) return 0;
    if(i == 1 && j != 0) return j-1;
    if(j == 1 && i != 0) return i-1;
    
    if(dp[i][j] != -1) return dp[i][j];
    
    int k; int mini = INT_MAX;
    for(k=1; k<i; k++){
        int ans = 1 + solve(i-k, j) + solve(k, j);
        mini = min(ans, mini);
    }
    
    int min2 = INT_MAX;
    for(k=1; k<j; k++){
        int ans = 1 + solve(i, j-k) + solve(i, k);
        min2 = min(ans, min2);
    }
    
    return dp[i][j] = min(mini, min2);
    
}



int32_t main(){

	// freopen("input.txt", "r", stdin);

	// freopen("output.txt", "w", stdout);


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n, m; cin>>n>>m;
    memset(dp, -1, sizeof dp);
    cout << solve(n, m);

    
    return 0;
}