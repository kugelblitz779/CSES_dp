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

int maxPage(int n, int w, vector<int> &price, vector<int> &page){
    
    vector<vector<int>> dp(n+1, vector<int>(w+1));
    
    for(int i=1; i<n+1; i++){
        for(int j=1; j<w+1; j++){
            if(price[i-1] <= j){
                dp[i][j] = max(dp[i-1][j-price[i-1]] + page[i-1], dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    return dp[n][w];
}




int32_t main(){

	// freopen("input.txt", "r", stdin);

	// freopen("output.txt", "w", stdout);


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n, w; cin>>n>>w;
    
    vector<int> price(n);
    for(int i=0; i<n; i++){
        cin>>price[i];
    }
    vector<int> page(n);
    for(int i=0; i<n; i++){
        cin>>page[i];
    }

    
    cout<<maxPage(n, w, price, page);

    return 0;
}