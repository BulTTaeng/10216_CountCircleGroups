#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <cstring>

using namespace std;

int T , N;

bool visit[5001][5001];
int inp[5001][5001];

struct st{
    int x;
    int y;
    int r;
}typedef st;

vector<st> v;

void dfs(st t);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> T;
    int sx , sy , r;
    st temp, newone;

    for(int qq = 0;  qq< T ;qq++){
        cin >> N;
        v.clear();
        int ans = 0;
        memset(visit ,false ,sizeof(visit));

        for(int i =0; i<N; i++){
            cin >> sx >> sy >> r;
            temp.x = sx;
            temp.y = sy;
            temp.r = r;
            v.push_back(temp);        
        }

        for(int i =0; i<v.size(); i++){
            if(!visit[v[i].x][v[i].y]){
                ans++;
                dfs(v[i]);
            }
        }

        cout << ans << "\n";

    }// end of qq


}

void dfs(st t){
    
    visit[t.x][t.y] = true;

    for(int i =0; i<v.size(); i++){

        double dis =0;
        int xdis = (t.x - v[i].x) * (t.x - v[i].x);
        int ydis = (t.y - v[i].y) * (t.y - v[i].y);

        dis = sqrt(xdis+ydis);

        if(dis <= t.r + v[i].r){
            if(!visit[v[i].x][v[i].y]){
                st nn;
                nn.x = v[i].x;
                nn.y = v[i].y;
                nn.r = v[i].r;
                dfs(nn);
            }
        }
        
    }
}