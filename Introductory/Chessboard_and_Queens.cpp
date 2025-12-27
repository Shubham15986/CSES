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

bool isSafe(int row,int col,vector<string> &v){
    int n=row,m =col;
    while(n--){
        if(v[n][col]=='Q')return false;
    }
    n=row;
    while(m--){
        if(v[n][m]=='Q')return false;
    }
    m=col;
    while(n-- && m--){
        if(v[n][m] == 'Q')return false;
    }
    n=row,m=col;

    while(n<8 && m>=0){
        if(v[n][m] == 'Q') return false;
        n++;m--;
    }
    return true;


}

void solve(int col,int n, vector<string> &v, vector<vector<string>> &ans){
    if(col==8){
        ans.pb(v);
        return;
    }

    rep(i,0,n){
        if(v[i][col] == '*')continue;
        if(isSafe(i,col,v)){
            v[i][col] = 'Q';
            solve(col+1,n,v,ans);
            v[i][col] = '.';
        }
        
    }
}

void boom(){
    vector<string> v(8);
    rep(i,0,8)cin>>v[i];
    vector<vector<string>> ans;
    solve(0,8,v,ans);
    cout<<ans.size();

}
int32_t main() { 
   int t; //cin>>t;
   t=1;
   

   while(t--){
    boom();
   }

}
