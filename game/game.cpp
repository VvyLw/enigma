// 漢字ゲーム(C++)
/*
 * Author: VvyLw
 * Original: KIRIGIRISU
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <algorithm>
#include <numeric>
int main() {
    std::random_device seed_gen;
    std::mt19937 engine{seed_gen()};
    std::ifstream in("problems/in.txt");
    std::ifstream out("problems/out.txt");
    std::vector<std::string> quiz, ans;
    while(!in.eof()) {
        std::string s;
        std::getline(in, s);
        quiz.emplace_back(s);
    }
    while(!out.eof()) {
        std::string s;
        std::getline(out, s);
        ans.emplace_back(s);
    }
    const int cnt = 5;
    std::vector<int> id(quiz.size()), rnd_id;
    std::iota(id.begin(), id.end(), 0);
    std::sample(id.begin(), id.end(), std::back_inserter(rnd_id), cnt, engine);
    std::cout << "漢字ゲーム\n";
    std::cout << "*************************************\n";
    std::cout << "* 答えはひらがなで入力して下さい\n";
    std::cout << "* UTF-8環境を想定しています\n";
    std::cout << "* C++17以上で動作します\n";
    std::cout << "*************************************\n";
    std::cout << "準備はよろしいですか(y/n): ";
    std::string ok;
    while(1) {
        std::cin >> ok;
        if(ok == "Y" || ok == "y") {
            std::cout << "では始めます\n";
            break;
        } else if(ok == "N" || ok == "n") {
            std::cout << "準備ができたらまた実行して下さいね\n";
            std::exit(0);
        } else {
            std::cout << "YかNを入力してください(y/n): ";
        }
    }
    int ac = 0;
    for(int i = 0; i < cnt; ++i) {
        std::cout << "--------------------------------------\n";
        std::cout << 'Q' << i + 1 << ". " << quiz[rnd_id[i]] << '\n';
        std::string input;
        std::cin >> input;
        if(input == ans[rnd_id[i]]) {
            std::cout << "Correct Answer\n";
            ac++;
        } else {
            std::cout << "Wrong Answer\n";
            std::cout << "Answer: " << ans[rnd_id[i]] << '\n';
        }
    }
    std::cout << "--------------------------------------\n";
    std::cout << "Answer Count: " << ac << '\n';
    std::cout << "GAME OVER\n";
}