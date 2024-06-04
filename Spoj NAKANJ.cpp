#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9+10;
bool vis[8][8];
int level[8][8];
vector<pair<int,int>> moments={
    {2,1},{2,-1},
    {-2,1},{-2,-1},
    {1,2},{-1,2},
    {1,-2},{-1,-2}
};
pair<int,int> getXY(string str){
    int x=str[0]-'a';
    int y=str[1]-'1';
    return {x,y};
}
void reset(){
    for(int i=0; i<8; ++i){
        for(int j=0; j<8; ++j){
            // level[i][j]=-1;
            level[i][j]=INF;
            vis[i][j]=0;
        }
    }
}
bool valid(int x,int y){
    if(x<0 || x>=8)return false;
    if(y<0 || y>=8)return false;
    return true;
}
int bfs(pair<int,int> src,pair<int,int> dest){
    int x=src.first;
    int y=src.second;

    queue<pair<int,int>> q;
    q.push({x,y});
    vis[x][y]=1;
    level[x][y]=0;
    while(!q.empty()){
        auto vertex=q.front();
        q.pop();
        int v_x=vertex.first;
        int v_y=vertex.second;
        for(auto val:moments){
            int child_x=val.first+v_x;
            int child_y=val.second+v_y;

            if(!valid(child_x,child_y))continue;
            if(vis[child_x][child_y])continue;

            q.push({child_x,child_y});
            vis[child_x][child_y]=1;
            level[child_x][child_y]=level[v_x][v_y]+1;
        }
        // if(level[dest.first][dest.second]!=-1)return level[dest.first][dest.second];
        if(level[dest.first][dest.second]!=INF)return level[dest.first][dest.second];
    }
    return level[dest.first][dest.second];
}
int main(){
    int n;
    cin>>n;
    while(n--){
        reset();
        string s1,s2;
        cin>>s1>>s2;
        pair<int,int> src=getXY(s1);
        pair<int,int> dest=getXY(s2);
        cout<<bfs(src,dest)<<endl;
    }
}
