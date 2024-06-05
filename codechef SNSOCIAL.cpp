#include<bits/stdc++.h>
using namespace std;
//Problem Link: https://www.codechef.com/SNCKPB17/problems/SNSOCIAL/

const int INF = 1e9+10;
const int N=1e3+7;

int vis[N][N];
int lev[N][N];
int mat[N][N];
int n,m;

vector<pair<int,int>> moments={
    {0,1},{0,-1},{1,0},{-1,0},
    {1,1},{-1,-1},{-1,1},{1,-1}
};

bool isValid(int x,int y){
    if(x<0 || x>=n)return false;
    if(y<0 || y>=m)return false;
    return true;
}
int bfs(){
    int maxVal=mat[0][0];
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            maxVal=max(mat[i][j],maxVal);
        }
    }
    queue<pair<int,int>> q;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(maxVal==mat[i][j]){
                q.push({i,j});
                vis[i][j]=1;
                lev[i][j]=0;
            }
        }
    }
    int ans=0;
    while(!q.empty()){
        pair<int,int> curr=q.front();
        q.pop();
        int x=curr.first;
        int y=curr.second;
        for(auto val: moments){
            int child_x=x+val.first;
            int child_y=y+val.second;
            if(!isValid(child_x,child_y))continue;
            if(vis[child_x][child_y])continue;

            q.push({child_x,child_y});
            vis[child_x][child_y]=1;
            lev[child_x][child_y]=lev[x][y]+1;

            ans=max(lev[child_x][child_y],ans);
        }
    }
    return ans;
}
void reset(){
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            vis[i][j]=0;
            lev[i][j]=INF;
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        reset();
        cin>>n>>m;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                cin>>mat[i][j];
            }
        }
        cout<<bfs()<<endl;
    }
}
