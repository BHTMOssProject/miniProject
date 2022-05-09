#include "person.h"

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
        printf("*** %d번 User ***\n", i+1);
        printf("이름 : %s | 나이 : %d | 성별 : %s | MBTI : %s\n", p[i].name, p[i].age, gender, p[i].mbti);
    }
    printf("-----------------------------\n");
    printf("	현재 총 User : %d명\n", user_cnt);
    printf("-----------------------------\n");
}

int createPerson(Person *p, int count){

    printf("이름은? ");
    scanf("%s", p[count].name);
    getchar();
    printf("나이는? ");
    scanf("%d", &p[count].age);
    printf("성별은?(남자:0, 여자:1) ");
    scanf("%d", &p[count].gender);
    getchar();
    printf("mbti는? ");
    scanf("%s", p[count].mbti);
    getchar();
    
    return 1;
}

int readPerson(Person *p, int count) // 번호 입력 받고 그 사람 정보 출력
{
    int printNum;
    char gender[10];
    printf("몇번째 사람을 확인 하시겠습니까? ");
    scanf("%d", &printNum);
    printNum--;
    if (p[count].gender) 
            strcpy(gender, "여자");
        else
            strcpy(gender, "남자");
    printf("=====================================\n");    
    printf("사람: %s\n", p[printNum].name);
    printf("나이: %d\n", p[printNum].age);
    printf("성별: %s\n", gender);
    printf("mbti: %s\n", p[printNum].mbti);
    printf("=====================================\n");

    return 1;
}


// 업데이트 항목은 나이와 MBTI
int updateData(Person *p, int count) 
{
    int num;
    
    listPerson(p, count);

    printf("업데이트할 User 번호 (취소 : 0) : ");
    scanf("%d", &num);

    if (num == 0) return 0;

    printf("나이 : ");
    scanf("%d", &p[num-1].age);
    printf("MBTI : ");
    scanf(" %s", p[num-1].mbti);
    
    printf("=> 업데이트 완료!\n");

    return 1;
}

// 삭제 처리는 age = -1으로
int deletePerson(Person *p, int count)
{
    int num, answer;

    listPerson(p, count);

    printf("삭제할 User 번호 (취소 : 0) : ");
    scanf("%d", &num);

    if (num == 0) return 0;

    printf("정말로 삭제하시겠습니까? (삭제 : 1) ");
    scanf("%d", &answer);

    if (answer == 1) {
        p[num-1].age = -1;
        printf("=> 삭제됨\n");
    }

    getchar();
    return 1;
}