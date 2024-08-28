#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(NULL)); // 初始化亂數種子

    cout << "歡迎參加魷魚遊戲!這是數位版的玻璃橋遊戲。接下來將會沒有任何提示，你只能選0或1，你能夠活到第幾關呢?來挑戰看看吧!據說通過的能實現一個願望!\n\n";

    int level = 1;
    int last_answer = -1;
    int same_answer_count = 0;
    int win_count = 0;

    while (level <= 50) {
        cout << "第" << level << "關: ";
        int answer = rand() % 2; // 產生隨機答案

        int guess;
        cin >> guess;

        if (guess != 0 && guess != 1) {
            cout << "輸入錯誤，請輸入0或1。\n\n";
            continue;
        }

        if (guess == answer) {
            cout << "恭喜你通過第" << level << "關!\n\n";
            same_answer_count = 0;
            win_count++;

            if (win_count % 5 == 0 && level < 50) {
                cout << "恭喜你已經過了" << level << "關了。\n\n";
            }

            level++;
        } else {
            if (guess == last_answer && same_answer_count == 2) {
                cout << "你以為答案都會是一樣的嗎\n\n";
                same_answer_count = 0;
            } else {
                cout << "你輸了\n\n";
                same_answer_count++;
            }

            cout << "你共通過了" << level - 1 << "關。\n";
            cout << "是否要再玩一次? (輸入0退出，輸入1再玩一次) ";
            int play_again;
            cin >> play_again;
            if (play_again == 0) {
                break;
            } else {
                level = 1;
                last_answer = -1;
                same_answer_count = 0;
                win_count = 0;
                cout << "\n\n";
            }
        }

        last_answer = answer;

        if (level == 10) {
            cout << "雖然你還沒達到能達成的願望，但你已經獲得心態崩潰免疫了，此buff能祝福你接下來更容易通關。\n\n";
        }
    }

    if (level > 50)
