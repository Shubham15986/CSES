#include<iostream>
#include<algorithm>
  #include <iomanip>
  #include<queue>



#include<unordered_map>
#include<map>
#include<set>
#include<vector>
#include <numeric>
#include<cstring>
#include<climits>

using namespace std;            

#define int long long               
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ff first
#define ss second
#define sz(x) (int)(x).size()



#define repd(i, a, b) for (int i = (a); i >= (b); i--)
#define each(x, a) for (auto &x : a)
const int mod = 1e9 + 7;
#define int long long

#define vvi vector<vector<int>>
#define pii pair<int,int>
#define vii vector<pii>
#define in(v,n) rep(i,0,n) cin>>v[i];
#define out(v,n) rep(i,0,n) cout<<v[i]<<" "; cout<<endl;
#define pairout(v,n) rep(i,0,n) cout<<v[i].first<<" "<<cout<<v[i].second<<" "; cout<<endl;
const int INF = -1e9;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define vi vector<int>

void boom(){
    int n;cin>>n;
    vi v(n);
    rep(i,0,n) cin>>v[i];
    int maxi = 1000*n;
    vector<vector<bool>> dp(n+1,vector<bool>(maxi+1));
    dp[0][0] = true;
    int cnt =0;

    rep(i,1,n+1){
        rep(j,0,maxi+1){
            dp[i][j] = dp[i-1][j];
            if(j>=v[i-1] && dp[i-1][j-v[i-1]] ){
                dp[i][j] = true;
                cnt++;
            }
        }
    }
   
    vi ans;
    rep(i,1,maxi+1){
        if(dp[n][i]) ans.pb(i);
    }
    cout<<ans.size()<<endl;
    rep(i,0,ans.size()){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

}

int32_t main() { 
   int t; //cin>>t;
   t=1;

   while(t--){
    boom();
   }

}
