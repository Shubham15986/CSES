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
char paths[4]  = {'L' , 'R', 'D', 'U'};


void boom(){
   int n,m;cin>>n>>m;
   vvi v(n,vi(m,0));
   int srow=-1,scol=-1,erow=-1,ecol=-1;
   rep(i,0,n){
    rep(j,0,m){
        char c;cin>>c;
        if(c=='#') v[i][j] =0;
        else if(c == '.') v[i][j] = 1;
        else if( c == 'A'){
            srow =i,scol = j;v[i][j] = 1;

        }
        else {
            erow = i,ecol = j;v[i][j] = 1;
        }
    }
   }
   vvi vis(n,vi(m,0));
   vector<vector<char>> path(n,vector<char>(m));
   
   queue<pii> q;
   bool flag = false;
   q.push({srow,scol});
   vis[srow][scol] = 1;

   while(!q.empty()){
     auto it = q.front();
     q.pop();
     if(it.first == erow && it.second == ecol){
            flag = true;
            break;
        }


     for(int i=0;i<4;i++){
        int nr = dirs[i][0] + it.first;
        int nc = dirs[i][1] + it.second;
        
        if( nc <0 || nr <0 || nr >= n || nc >= m || vis[nr][nc] || v[nr][nc] == 0) continue;
        
        vis[nr][nc] = 1;
        path[nr][nc] = paths[i];
        q.push({nr,nc});
        
     }
   }
    string ans = "";
   if(!flag){
    cout<<"NO\n";
   }
  
   else{
     int i = erow, j= ecol;
     while(i != srow || j != scol){
       char ch = path[i][j];
       ans.push_back(ch);

       if(ch == 'L') j+=1;
       else if( ch == 'R') j-=1;
       else if( ch == 'U') i+=1;
       else i-=1;
       

       }
     reverse(ans.begin(), ans.end());
     cout<<"YES\n"<<ans.size()<<"\n"<<ans<<"\n";
     
   }
     
}
int32_t main() {
    
   int t; //cin>>t;
   t=1;

   while(t--){
    boom();
   }
}