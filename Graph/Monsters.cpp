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
const int INF = 1e9;
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
   vector<string> v(n);
   
   queue<pii> mq;
   int srow=-1,scol=-1;
   int ansr =-1,ansc = -1;
   rep(i,0,n){
     cin>>v[i];
    rep(j,0,m){
    char c = v[i][j];
    if(c == 'A'){ 
      srow = i; scol = j;
     }
    if(c == 'M'){
      mq.push({i,j});
     }
    }
   }
   vvi dis(n,vi(m,INF));
  //  vis[srow][scol] =1;

  queue<pii> nmq = mq;
  while(!nmq.empty()){
    auto it = nmq.front(); nmq.pop();
    dis[it.first][it.second] = 0;
  }

   while(!mq.empty()){
     auto it = mq.front();mq.pop();
     for(int i=0;i<4;i++){
       int nr = it.first + dirs[i][0];
       int nc = it.second + dirs[i][1];
       

       if( nr<0 || nr>=n || nc<0 || nc>=m || v[nr][nc] == '#') continue;
       if(dis[nr][nc]>dis[it.first][it.second]+1){
            dis[nr][nc] = 1+dis[it.first][it.second];
            mq.push({nr,nc});
        }

     }
   }
   vvi vis(n,vi(m,INF));
   vector<vector<char>> path(n,vector<char>(m));
   


  if(dis[srow][scol] == 0){
    cout << "NO\n";
    return;
  }
  if(srow == 0 || srow == n-1 || scol == 0 || scol == m-1){
    cout<<"YES\n"<<"0"<<endl;
    return;
   }
   
   queue<pii> q;
   bool flag = false;
   q.push({srow,scol});
   vis[srow][scol] = 0;

   while(!q.empty()){
     auto it = q.front();
     q.pop();
     for(int i=0;i<4;i++){
        int nr = dirs[i][0] + it.first;
        int nc = dirs[i][1] + it.second;

       if(nr < 0 || nr >= n || nc < 0 || nc >= m || v[nr][nc] == '#' || vis[nr][nc] != INF || vis[it.first][it.second]+1 >= dis[nr][nc]) continue;
       
        vis[nr][nc] = vis[it.first][it.second]+1;
        path[nr][nc] = paths[i];
 
       

        if(nr ==0 || nc == 0 || nr == n-1 || nc ==m-1 ){
            ansr= nr;ansc = nc;
            flag = true;
            break;
        }
       
        q.push({nr,nc});
        
     }
   }
    string ans = "";
   if(!flag){
    cout<<"NO\n";
   }
  
   else{
     int i = ansr, j= ansc;
     while(i != srow || j != scol){
       char ch = path[i][j];
       ans.push_back(ch);

       if(ch == 'L') j+=1;
       else if( ch == 'R') j-=1;
       else if( ch == 'U') i+=1;
       else i-=1;
       

       }
     reverse(ans.begin(), ans.end());
     cout<<"YES"<<endl;
     cout<<ans.size()<<endl;
     cout<<ans<<endl;;
     
   }
     
}
int32_t main() {
    
   int t; //cin>>t;
   t=1;

   while(t--){
    boom();
   }
}