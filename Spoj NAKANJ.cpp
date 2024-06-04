#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
const int INF = 1e9+10;
int vis[8][8];
int level[8][8];

vector<pair<int,int>> moments = {
    {1,2},{-1,2},
    {2,1},{2,-1},
    {-2,1},{-2,-1},
    {-1,-2},{1,-2},
};

bool isValid(int a, int b){
    if(a < 0 || b<0) return false;
    if(a >=8 || b >= 8) return false;
    return true;
}

pair<int,int> conv(string s1){
    int a = (s1[0] - 'a');
    int b = (s1[1] - '1');
    return {a,b};
}

int bfs(pair<int,int> src, pair<int,int> dest){
    queue<pair<int,int>> q;
    q.push(src);
    vis[src.first][src.second] = 1;
    level[src.first][src.second] = 0;

    while(!q.empty()){
        pair<int,int> cur_v = q.front();
        int x = cur_v.first;
        int y = cur_v.second;
        q.pop();

        for(auto p:moments){
            int child_x = p.first+x;
            int child_y = p.second+y;

            if(!isValid(child_x,child_y)) continue;

            if(!vis[child_x][child_y]){
                q.push({child_x,child_y});
                vis[child_x][child_y] = 1;
                level[child_x][child_y] = level[x][y] + 1;
            }
        }
        if(level[dest.first][dest.second] != INF) return level[dest.first][dest.second];
    }
    return level[dest.first][dest.second];
}

void reset(){
    for (int i = 0; i < 8; ++i){
        for (int j = 0; j < 8; ++j){
            level[i][j] = INF;
            vis[i][j] = 0;
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        reset();
        string s1,s2; 
        cin>>s1>>s2;
        pair<int,int> src = conv(s1);
        pair<int,int> dest = conv(s2);

       cout<<bfs(src,dest)<<endl;
    }
}
