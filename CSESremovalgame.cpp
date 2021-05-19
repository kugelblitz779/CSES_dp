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
 


int32_t main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n; cin>>n;

    vi arr(n);
    f(n) cin>>arr[i];

    int dp[n][n];
    memset(dp, 0, sizeof dp);

    int r = 0, c= 0;
    while(r < n && c < n){
        dp[r][c] = arr[r];
        r++; 
        c++;
    }

    c=1; r= 0;
    while(r < n && c < n){
        dp[r][c] = max(arr[r], arr[c]);
        r++;
        c++;
    }

    for(int col=2; col<n; col++){
        int r = 0;
        int c = col;
        while(r < n && c < n){
            dp[r][c] = max(min(dp[r+2][c], dp[r+1][c-1]) + arr[r], min(dp[r+1][c-1], dp[r][c-2]) + arr[c]);
            r++; c++; 
        }
    }


    cout << dp[0][n-1];
    
    return 0;
}