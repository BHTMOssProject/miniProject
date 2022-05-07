#include "person.h"

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