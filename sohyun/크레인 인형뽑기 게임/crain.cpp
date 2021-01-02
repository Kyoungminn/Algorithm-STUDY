/*
 < 크레인 인형 뽑기 게임 >
 게임 화면의 격자의 상태가 담긴 2차원 배열 board와 인형을 집기 위해 크레인을 작동시킨 위치가 담긴 배열 moves가 매개변수로 주어질 때,
 크레인을 모두 작동시킨 후 터트려져 사라진 인형의 개수를 return 하도록 solution 함수를 완성해주세요.
 */

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> basket(moves.size(), 0);

    for (int i = 0; i < moves.size(); i++) {

        int pwd, j;
        for (j = 0; j < board[0].capacity(); j++) {
            if (board[j][moves[i] - 1] != 0) {
                pwd = board[j][moves[i] - 1];
                board[j][moves[i] - 1] = 0;
                break;
            }
        }
        if (j == board[0].capacity()) continue;

        if (basket.size() != 0) {
            if (basket.back() == pwd) {
                answer += 2;
                basket.pop_back();
                continue;
            }
        }
        basket.push_back(pwd);
    }
    return answer;
}