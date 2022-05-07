#include "manager.h"

// 커뮤니티(모든 User) 확인
void listPerson(Person *p, int count)
{
    int user_cnt = 0;
    char gender[10];

    for (int i = 0; i < count; i++) {
        if (p[i].age == -1) continue;
        if (p[i].gender) 
            strcpy(gender, "여자");
        else
            strcpy(gender, "남자");
        user_cnt++;
        printf("-----------------------------\n");
        print("*** %d번 User ***\n", i+1);
        printf("이름 : %s | 나이 : %d | 성별 : %s | MBTI : %s\n", p[i].name, p[i].age, p[i].gender, p[i].mbti);
    }
    printf("-----------------------------\n");
    printf("	현재 총 User : %d명\n", user_cnt);
    printf("-----------------------------\n");
}

// 메뉴바
int selectMenu()
{
    int menu;

    printf("\n 한동 친구 찾기 - 나의 친구가 되어줘!\n");
    printf("0. 종료\n");
    printf("1. User 등록\n");
    printf("2. 커뮤니티 확인\n");
    printf("3. User 업데이트\n");
    printf("4. User 삭제\n");
    printf("=> 선택할 메뉴 : ");
    scanf("%d", &menu);

    return menu;
}