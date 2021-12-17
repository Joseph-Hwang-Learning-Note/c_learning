
// BFS <=> DFS
// DFS <- recurse
// BFS <- Queue, FIFO(first in, first out)

/*

head++
tail++

if (head == tail) {
    finish()
}

*/

#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Pos {
    int x;
    int y;
    Pos(int _y, int _x) { y = _y; x = _x; }
};

int bfs(vector< vector<char> > map, Pos start_pos, Pos dest_pos)
{
    const int n = map.size();
    const int m = map[0].size();

    int deltaY[4] = { -1, 0, 1, 0 }; 
    int deltaX[4] = { 0, 1, 0, -1 };

    vector< vector<bool> > checked(n, vector<bool>(m));
    vector< vector<int> > dist(n, vector<int>(m));
    queue<Pos> q;

    q.push(start_pos);
    checked[start_pos.y][start_pos.x] = true;
    dist[start_pos.y][start_pos.x] = 0;

    while (!q.empty()) {

        Pos pos = q.front();
        q.pop();
        int nowY = pos.y;
        int nowX = pos.x;


        for (int i = 0; i < 4; ++i) {  
            int nextY = nowY + deltaY[i];
            int nextX = nowX + deltaX[i];

            if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m)
                continue;
            if (map[nextY][nextX] == '#' || map[nextY][nextX] == '$')
                continue;
            if (checked[nextY][nextX])
                continue;
            
            q.push(Pos(nextY, nextX));
            checked[nextY][nextX] = true;
            dist[nextY][nextX] = dist[nowY][nowX] + 1;
        }
    }
        
    if (!checked[dest_pos.y][dest_pos.x])
        return -1;
    else
        return dist[dest_pos.y][dest_pos.x];
}

int main()
{
    int N;
    int i, j;

    cin >> N;

    vector< vector<char> > map;
    vector<char> map_row;

    string str_input;
    vector< Pos > fire_extinguishers;
    
    int fire_pos_x;
    int fire_pos_y;

    for (i = 0; i < N; i++) {
        cin >> str_input;
        for (j = 0; j < str_input.length(); j++) {
            if (str_input[j] == 'A') {
                fire_extinguishers.push_back(Pos(i, j));
            }
            if (str_input[j] == '$') {
                fire_pos_x = i;
                fire_pos_y = j;
            }
            map_row.push_back((char)str_input[j]);
        }
        map.push_back(map_row);
        map_row.clear();
    }

    Pos fire_pos = Pos(fire_pos_y, fire_pos_x);

    int start_pos_x;
    int start_pos_y;

    cin >> start_pos_x;
    cin >> start_pos_y;

    Pos start_pos = Pos(start_pos_y, start_pos_x);

    int to_fire_exts[fire_extinguishers.size()];
    for (i = 0; i < fire_extinguishers.size(); i++) {
        to_fire_exts[i] = bfs(map, start_pos, fire_extinguishers[i]);
    }

    int to_fires[fire_extinguishers.size()];
    for (i = 0; i < fire_extinguishers.size(); i++) {
        to_fires[i] = bfs(map, fire_extinguishers[i], fire_pos);
    }

    int results[fire_extinguishers.size()];
    for (i = 0; i < fire_extinguishers.size(); i++) {
        results[i] = to_fire_exts[i] + to_fires[i];
    }

    cout << *min_element(results, results + sizeof(results) / sizeof(results[0])) << endl;

    return 0;
}
