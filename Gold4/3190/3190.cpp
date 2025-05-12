#include <iostream>
#include <algorithm>
#include <vector>
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
    bool is_valid_;
    int time_;
    Snake() = default;
    Snake(Direction d , vector<vector<int>> body, bool is_valid, vector<pair<int,int>> body_info, int board_size) 
    : dir_(d), body_(body), is_valid_(is_valid), body_info_(body_info), board_size_(board_size) {}

    void go_next(vector<vector<int>>& board) {
        if(is_collide_wall()||is_collide_body()){
            is_valid_ = false;
            return;
        }
        move_(board, direction_exchange(dir_).first, direction_exchange(dir_).second);
    
        // cout <<  "Direction:" << static_cast<int>(dir_) << " | head's location: " << body_info_.back().first << ", "<< body_info_.back().second << endl; //디버깅 용
        return;
    }

    void change_direction(int isD) {
        if (isD==0) 
            dir_ = static_cast<Direction>((static_cast<int>(dir_) + 1) % 4); // 시계방향
        else 
            dir_ = static_cast<Direction>((static_cast<int>(dir_) + 3) % 4); // 반시계방향
    }

private:
    vector<vector<int>> body_;
    vector<pair<int,int>> body_info_; // 기존의 head, tail 교체. 몸이 생긴 순서를 저장하며 body_info_[0]이 tail, body_info_.back()이 head 역할 수행
    Direction dir_;
    int board_size_;
    
    pair<int,int> direction_exchange(Direction d){
        switch(d){
            case Direction::RIGHT:
                return {0,1};
            case Direction::DOWN:
                return {1,0};
            case Direction::LEFT:
                return {0,-1};
            case Direction::UP:
                return {-1,0};
        }
    }
    
    bool is_collide_wall() {
        int next_row = body_info_.back().first + direction_exchange(dir_).first;
        int next_col = body_info_.back().second + direction_exchange(dir_).second;
    
        return next_row < 0 || next_row >= board_size_ || next_col < 0 || next_col >= board_size_;
    }
    
    bool is_collide_body() {
        int next_row = body_info_.back().first + direction_exchange(dir_).first;
        int next_col = body_info_.back().second + direction_exchange(dir_).second;
    
        // 다음 위치가 몸체와 겹치는지 확인
        return body_[next_row][next_col] == 1;
    }
    
    void move_(vector<vector<int>>&board, int row, int col){
        if(board[body_info_.back().first+row][body_info_.back().second+col] == 1){ //사과가 있는 경우
            board[body_info_.back().first+row][body_info_.back().second+col] = 0; // 사과를 삭제
            body_[body_info_.back().first+row][body_info_.back().second+col] = 1; // 몸을 늘린다.
            body_info_.push_back({body_info_.back().first+row, body_info_.back().second+col}); // 머리의 위치 수정
        } else { // 사과가 없는 경우
            body_[body_info_.back().first+row][body_info_.back().second+col] = 1; // 몸을 늘린다.
            body_info_.push_back({body_info_.back().first+row, body_info_.back().second+col}); // 머리의 위치 수정
            body_[body_info_[0].first][body_info_[0].second] = 0; // body_ 에서 꼬리 삭제
            body_info_.erase(body_info_.begin(),body_info_.begin() + 1); // body_info_ 에서 꼬리부분 삭제
        }
    }
};


int main(){
    int board_size, apple_num;
    // cout << "Enter the size of board: " << endl;// 디버깅 용
    cin >> board_size;
    // cout << "Enter the number of apples: " << endl;// 디버깅 용
    cin >> apple_num;
    
    vector<vector<int>> board;
    board.assign(board_size, vector<int>(board_size, 0));
    vector<vector<int>> body = board;
    body[0][0] = 1;

    Snake s(Direction::RIGHT, body, true, {{0,0}}, board_size);
    s.time_ = 0;

    for(int i=0;i<apple_num;++i){
        int row, col;
        // cout << "Enter the location of the apple #"<< i << endl; // 디버깅 용
        cin >> row >> col;
        board[row - 1][col - 1] = 1;
        // 사과의 위치 정보 설정
    }

    int direction_change;
    // cout << "Enter the number of direction information: " << endl;// 디버깅 용
    cin >> direction_change;

    vector<pair<int, int>> change_list;

    for(int i=0; i<direction_change; ++i){
        int time;
        string change;
        // cout << "Enter the direction information #"<< i << endl;// 디버깅 용
        cin >> time >> change;
        pair<int,int> temp_pair;
        temp_pair.second = time;

        if(change == "D") temp_pair.first = 0; 
        // 0 은 시계방향 -> Direction++
        else temp_pair.first = 1; 
        // 1 은 반시계방향 -> Direction--
        change_list.push_back(temp_pair);
    }
// s.time_ 이 change_list[i].second 보다 작으면 go_next, is_valid_가 false 일 시에 즉시 종료. change_list[i].second == s.time_ 이면 i++
// s.time_ 증가도 다루어야함
    int c1 = 0;     
    while(s.is_valid_){
        
        s.go_next(board);
        s.time_++;

        if (change_list[c1].second == s.time_){
            s.change_direction(change_list[c1].first);
            if (c1 < change_list.size()) c1++; // c1은 change_list 크기 만큼만 증가.
        }
    }
    
    cout << s.time_ << endl;
}