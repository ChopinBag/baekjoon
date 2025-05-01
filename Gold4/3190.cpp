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
    bool is_valid_;
    int time_;
    Snake() = default;
    Snake(Direction d , vector<vector<int>> body) 
    : dir_(d), body_(body) {}

    bool go_next(vector<vector<int>>& board) {
        if(is_collide_body()||is_collide_wall()){
            this->is_valid_ = false;
            return false;
        }
        
        if(this->dir_==Direction::RIGHT){
            if(board[head_.first][head_.second+1]==1){
                this->body_[head_.first][++head_.second] = 1;
                board[head_.first][head_.second] = 0;
            }else{
                this->body_[head_.first][head_.second] = 0;
                this->body_[head_.first][++head_.second] = 1;
            }
        } else if(this->dir_==Direction::DOWN){
            if(board[head_.first+1][head_.second]==1){
                this->body_[++head_.first][head_.second] = 1;
                board[head_.first][head_.second] = 0;
            }else{
                this->body_[head_.first][head_.second] = 0;
                this->body_[++head_.first][head_.second] = 1;
            }
        } else if(this->dir_==Direction::LEFT){
            if(board[head_.first][head_.second-1]==1){
                this->body_[head_.first][--head_.second] = 1;
                board[head_.first][head_.second] = 0;
            }else{
                this->body_[head_.first][head_.second] = 0;
                this->body_[head_.first][--head_.second] = 1;
            }
        } else if(this->dir_==Direction::UP){
            if(board[head_.first-1][head_.second]==1){
                this->body_[--head_.first][head_.second] = 1;
                board[head_.first][head_.second] = 0;
            }else{
                this->body_[head_.first][head_.second] = 0;
                this->body_[--head_.first][head_.second] = 1;
            }
        }  
        this->time_++;
        return true;
    }
    
    void setup(int size) {
        this->body_.assign(size, vector<int>(size));
        this->body_[0][0] = 1; // 뱀의 첫번째 위치
        this->board_size_ = size;
        this->head_ = {0,0};
        this->time_ = 0;
        this->is_valid_ = true;
    }

    void change_direction(int isD) {
        if (isD==0) 
            this->dir_ = static_cast<Direction>((static_cast<int>(this->dir_) + 1) % 4); // Clockwise
        else 
            this->dir_ = static_cast<Direction>((static_cast<int>(this->dir_) + 3) % 4); // Counter-clockwise
    }

private:
    vector<vector<int>> body_; 
    Direction dir_;
    int board_size_;
    pair<int,int> head_;

    bool is_collide_wall(){
        if (this->dir_==Direction::RIGHT && this->head_.second==board_size_)return true;
        else if (this->dir_==Direction::LEFT && this->head_.second==0)return true;
        else if (this->dir_==Direction::DOWN && this->head_.first==board_size_)return true;
        else if (this->dir_==Direction::UP && this->head_.first==0)return true;

        else return false;
    }

    bool is_collide_body(){
        if(this->dir_==Direction::RIGHT && this->body_[this->head_.first][this->head_.second+1]==1) return true;
        else if(this->dir_==Direction::LEFT && this->body_[this->head_.first][this->head_.second-1]==1) return true;
        else if(this->dir_==Direction::DOWN && this->body_[this->head_.first+1][this->head_.second]==1) return true;
        else if(this->dir_==Direction::UP && this->body_[this->head_.first-1][this->head_.second]==1) return true;
        else return false;
    }
    
};


int main(){
    int board_size, apple_num;
    cout << "Enter the size of board: " << endl;
    cin >> board_size;
    cout << "Enter the number of apples: " << endl;
    cin >> apple_num;
    
    vector<vector<int>> board;
    board.assign(board_size, vector<int>(board_size, 0));
    vector<vector<int>> body;

    Snake s(Direction::RIGHT, body);
    s.setup(board_size);

    for(int i=0;i<apple_num;++i){
        int row, col;
        cout << "Enter the location of the apple #"<< i << endl;
        cin >> row >> col;
        board[row - 1][col - 1] = 1;
        // 사과의 위치 정보 설정
    }

    int direction_change;
    cout << "Enter the number of direction information: " << endl;
    cin >> direction_change;

    vector<pair<int, int>> change_list;

    for(int i=0; i<direction_change; ++i){
        int time;
        string change;
        cout << "Enter the direction information #"<< i << endl;
        cin >> time >> change;
        pair<int,int> temp_pair;
        temp_pair.second = time;

        if(change == "D") temp_pair.first = 0; 
        // 0 은 시계방향 -> Direction++
        else temp_pair.first = 1; 
        // 1 은 반시계방향 -> Direction--
        change_list.push_back(temp_pair);
    }

    for(int i=0;i<direction_change;++i){
        int j=0;
        while(j++ < change_list[i].second && s.go_next(board)){;}
        if(!s.is_valid_) break;
        
        s.change_direction(change_list[i].first);
    }
    cout << s.time_ << endl;
}