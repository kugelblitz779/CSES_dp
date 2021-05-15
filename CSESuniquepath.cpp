#include<bits/stdc++.h>
#define ll int64_t
#define pb emplace_back
#define mp make_pair
#define acc accumulate
#define f(n) for(int i=0;i<n;i++) 
#define f1(n) for(int i=1;i<n;i++) 
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000007
using namespace std;
typedef vector<int> vi;
const int mod = 1000000007;

int dp[1001][1001];
int solve(int i, int j, vector<string> &grid, int n){
    
    if((i == n - 1 && j == n - 1) && grid[i][j] == '.') return 1;   

    if(i < 0 || i >= n) return 0;    
    if(j < 0 || j >= n) return 0;
    if(grid[i][j] == '*') return dp[i][j] = 0;
    
    if(dp[i][j] != -1) return dp[i][j];
     
    
    return dp[i][j] = (solve(i+1, j, grid, n) + solve(i, j+1, grid, n))%mod;
}


int32_t main(){

	// freopen("input.txt", "r", stdin);

	// freopen("output.txt", "w", stdout);


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n; cin>>n;
    
    vector<string> grid;
    
    for(int i=0; i<n; i++){
        string x; cin>>x;
        grid.emplace_back(x);
    }
    
    memset(dp, -1, sizeof dp);
    cout<<solve(0, 0, grid, n);

    return 0;
}