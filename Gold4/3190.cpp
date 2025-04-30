#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

enum class Direction {
    RIGHT = 0,
    DOWN,
    LEFT,
    UP
};


class Snake{
    public:
        Snake() = default;
        Snake(vector<vector<int>> &b,Direction d = Direction::RIGHT){
            this->body = b;
            this->dir = d;
        };
        void go_next(Direction d){
            
        }
        void setup(vector<vector<int>> &b, int size){
            b.assign(size, vector<int>(size, 0));
            b[0][0] = 1; // 뱀 머리의 첫번째 위치
        }
        void change_direction(Direction &d, int isD){
            if(isD) d = static_cast<Direction>((static_cast<int>(d) + 1) % 4);
            else d = static_cast<Direction>((static_cast<int>(d) + 3) % 4);
        }

    private:
        vector<vector<int>> body;
        Direction dir;
        
};


int main(){
    int board_size, apple_num;
    cout << "Enter the size of board" << endl;
    cin >> board_size;
    cout << "Enter the number of apples" << endl;
    cin >> apple_num;
    
    vector<vector<int>> board;
    board.assign(board_size, vector<int>(board_size, 0));
    vector<vector<int>> body;

    Snake s;
    s.setup(body, board_size);

    for(int i=0;i<apple_num;++i){
        int row, col;
        cin >> row >> col;
        board[row - 1][col - 1] = 1;
        // 사과의 위치 정보 설정
    }

    int direction_change;
    cin >> direction_change;

    vector<vector<int>> change_list;
    change_list.assign(direction_change, vector<int>(2, 0));

    for(int i=0;i<direction_change;++i){
        int time;
        string change;
        cin >> time >> change;
        change_list[i][0] = time;

        if(change == "D") change_list[i][1] = 0; 
        // 0 은 시계방향 -> Direction++
        else change_list[i][0] = 1; 
        // 1 은 반시계방향 -> Direction--
    }
}