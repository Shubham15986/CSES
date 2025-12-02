#include<iostream>
#include<algorithm>
  #include <iomanip>



#include<unordered_map>
#include<map>
#include<set>
#include<vector>
#include <numeric>
#include<cstring>

using namespace std;


#define int long long               
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ff first
#define ss second
#define sz(x) (int)(x).size()


#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define repd(i, a, b) for (int i = (a); i >= (b); i--)
#define each(x, a) for (auto &x : a)
const int mod = 1e9 + 7;
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define vii vector<pii>
#define in(v,n) rep(i,0,n) cin>>v[i];
#define out(v,n) rep(i,0,n) cout<<v[i]<<" "; cout<<endl;
#define pairout(v,n) rep(i,0,n) cout<<v[i].first<<" "<<cout<<v[i].second<<" "; cout<<endl;
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int dirs[4][2] = {{0,-1},{0,1},{1,0},{-1,0}};
void dfs(vvi &vis, vvi &v,int i, int j){
    vis[i][j] = 1;
    int n = v.size();
    int m = v[0].size();

    for(auto it : dirs){
        int nr = i + it[0];
        int nc = j + it[1];

        if( nr <0 || nc < 0 || nr >=n || nc >= m || v[nr][nc] == 0 || vis[nr][nc]) continue;
         dfs(vis, v, nr, nc);
    }

}


void boom(){
   int n,m;cin>>n>>m;
   vvi v(n,vi(m));
   rep(i,0,n){
    rep(j,0,m){
        char c;cin>>c;
        c == '#'? v[i][j] = 0 : v[i][j] = 1;
    }
   }
   vvi vis(n,vi(m,0));
   int cnt =0;
   rep(i,0,n){
    rep(j,0,m){
        if(!vis[i][j] && v[i][j] == 1){
            dfs(vis, v, i, j);
            cnt++;
        }
        

    }
   }
   cout<<cnt<<endl;

     
}
int32_t main() {
    
   int t; //cin>>t;
   t=1;

   while(t--){
    boom();
   }
}