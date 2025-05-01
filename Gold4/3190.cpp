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


class Snake {
public:
    Snake() = default;
    Snake(Direction d = Direction::RIGHT) : dir_(d) {}

    void go_next(const vector<vector<int>> board) {
        
    }

    void setup(int size) {
        body_.assign(size, vector<int>(size));
        body_.push_back({0, 0}); // 뱀의 첫번째 위치
    }

    void change_direction(int isD) {
        if (isD) 
            dir_ = static_cast<Direction>((static_cast<int>(dir_) + 1) % 4); // Clockwise
        else 
            dir_ = static_cast<Direction>((static_cast<int>(dir_) + 3) % 4); // Counter-clockwise
    }

private:
    vector<vector<int>> body_; 
    Direction dir_;

    bool isCollide(){
        if (dir_==Direction::RIGHT || )
    }
};


int main(){
    int board_size, apple_num;
    cout << "Enter the size of board" << endl;
    cin >> board_size;
    cout << "Enter the number of apples" << endl;
    cin >> apple_num;
    
    vector<vector<int>> board;
    board.assign(board_size, vector<int>(board_size, 0));
    vector<vector<int>> body_;

    Snake s;
    s.setup(body_, board_size);

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