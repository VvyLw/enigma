/*
 *  繰り返しタイピング・ゲーム
 */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 5

int main(void) {
    char s[256];
    char kanji[20][256] = {
      "葛根湯",
      "乙字湯",
      "安中散",
      "十味敗毒湯",
      "八味地黄丸",
      "大柴胡湯",
      "小柴胡湯",
      "柴胡桂枝湯",
      "柴胡桂枝乾姜湯",
      "柴胡加竜骨牡蛎湯",
      "半夏瀉心湯",
      "黄連解毒湯",
      "半夏厚朴湯",
      "五苓散",
      "桂枝加朮附湯",
      "小青竜湯",
      "防已黄耆湯",
      "小半夏可茯苓湯",
      "消風散",
      "当帰芍薬散",
    };
    char kana[20][256] = {
      "かっこんとう",
      "おつじとう",
      "あんちゅうさん",
      "じゅうみはいどくとう",
      "はちみじおうがん",
      "だいさいことう",
      "しょうさいことう",
      "さいこけいしとう",
      "さいこけいしかんきょうとう",
      "さいこかりゅうこつぼれいとう",
      "はんげしゃしんとう",
      "おうれんげどくとう",
      "はんげこうぼくとう",
      "ごれいさん",
      "けいしかじゅつぶとう",
      "しょうせいりゅうとう",
      "ぼういおうぎとう",
      "しょうさんげかぶくりょうとう",
      "しょうふうさん",
      "とうきしゃくやくさん",
    };

    int min = 0, range = 20;
    int i, j;
    int num[N] = { 0 };

    srand((unsigned int)time(NULL));

    int score = 0;  // 得点

    for (i = 0; i < N; i++) {
        do{
            num[i] = rand() % range + min;
            for (j = 0; j < i; j++) {
                if (num[i] == num[j])break;
            }
        } while (i != j);
    }

    for (i = 1; i <= 5; i++) {

        printf("第%d問: %s:\n", i, kanji[num[i]]);
        scanf("%s", s);
        if (strcmp(s, kana[num[i]]) == 0) {
            printf("正解!\n");
            score++;
        }
        else {
            printf("間違い!正しくは「%s」\n", kana[num[i]]);
        }
    }
    printf("%d問正解\n", score);

    return 0;
}