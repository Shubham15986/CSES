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
vi dp;
//vi ends;
int f(int n ,vector<pair<pair<int,int>,int>> &v, vi &ends ){
    if(n==0)return 0;
    if(dp[n] != -1)return dp[n];
    int notpick = f(n-1,v,ends);
    int pick=v[n-1].second;
    int x = v[n-1].first.first;
    int j =upper_bound(ends.begin(),ends.end(), x-1)-ends.begin();
    pick += f(j,v,ends);
    return dp[n] = max(pick,notpick);
    

}
void boom(){
    int n;cin>>n;
    int m=n;
    vi ends;
    vector<pair<pair<int,int>,int>> v;
    while(n--){
        int a,b,c;cin>>a>>b>>c;
        v.pb({{a,b},c});
    }
    sort(v.begin(), v.end(), [](auto &a, auto &b){
        return a.first.second<b.first.second;
    });
    
    rep(i,0,m){
        ends.pb(v[i].first.second);
    }
    dp.assign(m+1, -1);
    cout<<f(m,v,ends);


}
int32_t main() { 
   int t; //cin>>t;
   t=1;

   while(t--){
    boom();
   }

}
