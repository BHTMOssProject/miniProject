#include "person.h"

// 커뮤니티(모든 User) 확인 
void listPerson(Person *p, int count)
{
    int user_cnt = 0;
    char gender[10];

    printf("\n※ 한동 커뮤니티\n");
    for (int i = 0; i < count; i++) {
        if (p[i].age == -1) continue;
        if (p[i].gender) 
            strcpy(gender, "여자");
        else
            strcpy(gender, "남자");
        user_cnt++;
        printf("------------------------------------------------------\n");
        printf("*** %d번 User ***\n", i+1);
        printf("이름 : %s | 나이 : %d | 성별 : %s | MBTI : %s\n", p[i].name, p[i].age, gender, p[i].mbti);
    }
    printf("------------------------------------------------------\n");
    printf("=> 현재 총 User : %d명\n", user_cnt);
    printf("------------------------------------------------------\n");
}

int createPerson(Person *p, int count){

    printf("\n※ User 등록\n");
    printf("--------------------------\n");
    printf("이름은? ");
    scanf("%s", p[count].name);
    getchar();
    printf("나이는? ");
    scanf("%d", &p[count].age);
    printf("성별은? (남자:0, 여자:1) ");
    scanf("%d", &p[count].gender);
    getchar();
    printf("MBTI는? ");
    scanf("%s", p[count].mbti);
    getchar();
    printf("=> 등록 완료\n");
    
    return 1;
}

int readPerson(Person *p, int count) // 번호 입력 받고 그 사람 정보 출력
{
    int printNum;
    char gender[10];
    printf("\n※ User 검색\n");
    printf("--------------------------------------\n");
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
    printf("MBTI: %s\n", p[printNum].mbti);
    printf("=====================================\n");

    return 1;
}


// 업데이트 항목은 나이와 MBTI
int updateData(Person *p, int count) 
{
    int num;
    
    listPerson(p, count);

    printf("\n※ User 업데이트\n");
    printf("--------------------------------------\n");
    printf("업데이트할 User 번호 (취소 : 0) : ");
    scanf("%d", &num);

    if (num == 0) return 0;

    printf("나이 : ");
    scanf("%d", &p[num-1].age);
    printf("MBTI : ");
    scanf(" %s", p[num-1].mbti);
    
    printf("=> 업데이트 완료\n");

    return 1;
}

// 삭제 처리는 age = -1으로
int deletePerson(Person *p, int count)
{
    int num, answer;

    listPerson(p, count);

    printf("\n※ User 삭제\n");
    printf("------------------------------------\n");
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

void checkSimilarity(Person *p, int count)
{   

    listPerson(p, count);

    int n1, n2, s_count=0;
    printf("\n유사도를 확인하고 싶은 사람들의 번호를 입력해주세요: \n");
    scanf("%d %d", &n1, &n2);
    n1 = n1-1;
    n2 = n2-1;

    if(strcmp(p[n1].name, p[n2].name)==0) s_count++; 
    if(p[n1].gender==p[n2].gender) s_count++; 
    if(p[n1].age==p[n2].age) s_count++;
    if(strcmp(p[n1].mbti, p[n2].mbti)==0) s_count++; 

    int similarity = (s_count*100)/4;
    printf("%s와 %s의 유사도는 %d%%입니다.\n", p[n1].name, p[n2].name, similarity);
    if(similarity>=50) printf("좋은 친구가 될 수 있을 거 같아요!^^\n");
    else printf("친구는 서로 맞춰가는 거죠! 좋은 친구가 되도록 노력해보세요^^\n");

}

void leaveMessage(Person *p, int count)
{
    listPerson(p, count);

    int m_num;

    printf("메시지를 남기고 싶은 사람의 번호를 입력하세요: \n");
    scanf("%d", &m_num);
    getchar();
    m_num -= 1;
    printf("메시지를 남겨주세요\n");
    scanf("%[^\n]s", p[m_num].message);
    printf("메시지가 전달 되었습니다!\n");
    printf("커뮤티에서 확인해보세요\n");


}

void checkMessage(Person *p, int count)
{   
    int c_num;
    listPerson(p, count);

    printf("메시지를 확인하고 싶은 번호를 입력하세요: \n");
    scanf("%d", &c_num);
    c_num -= 1;
    if(strcmp(p[c_num].message,"")!=0)
    {
        printf("%s님에게 전달된 메시지 입니다.\n", p[c_num].name);
        printf("%s\n", p[c_num].message);
    }    
    else
    {
        printf("%s님에게 전달된 메시지가 없습니다\n", p[c_num].name);
    }   
    
}
