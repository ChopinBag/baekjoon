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
    Snake(Direction d = Direction::RIGHT, vector<vector<int>> body) 
    : dir_(d), body_(body) {}

    void go_next(const vector<vector<int>> board) {
        
    }
    // 뱀의 머리는 2, 뱀의 몸통은 1, 빈공간은 0
    void setup(int size) {
        body_.assign(size, vector<int>(size));
        body_[0][0] = 2; // 뱀의 첫번째 위치
        this->board_size_ = size;
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
    int board_size_;

    bool is_collide_wall(){
        if (dir_==Direction::RIGHT && any_of(body_.begin(),body_.end(),[](auto elem){
            if(elem[board_size_]==2)return true;
            else return false;
        })) return true;
        
        else if (dir_==Direction::LEFT && any_of(body_.begin(),body_.end(),[](auto elem){
            if(elem[0]==2)return true;
            else return false;
        })) return true;

        else if (dir_==Direction::UP && any_of(body_[0].begin(),body_[0].end(),[](auto elem){
            if(elem==2)return true;
            else return false;
        })) return true;

        else if (dir_==Direction::DOWN && any_of(body_[board_size_].begin(),body_[board_size_].end(),[](auto elem){
            if(elem==2)return true;
            else return false;
        })) return true;

        else {
            cout << "Error in <is_Collide_wall>" << endl;
        }
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
    vector<vector<int>> body;

    Snake s(Direction::RIGHT, body);
    s.setup(board_size);

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