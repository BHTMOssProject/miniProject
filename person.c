#include "person.h"

// Ŀ�´�Ƽ(��� User) Ȯ�� 
void listPerson(Person *p, int count)
{
    int user_cnt = 0;
    char gender[10];

    for (int i = 0; i < count; i++) {
        if (p[i].age == -1) continue;
        if (p[i].gender) 
            strcpy(gender, "����");
        else
            strcpy(gender, "����");
        user_cnt++;
        printf("-----------------------------\n");
        printf("*** %d�� User ***\n", i+1);
        printf("�̸� : %s | ���� : %d | ���� : %s | MBTI : %s\n", p[i].name, p[i].age, gender, p[i].mbti);
    }
    printf("-----------------------------\n");
    printf("	���� �� User : %d��\n", user_cnt);
    printf("-----------------------------\n");
}

int createPerson(Person *p, int count){

    printf("�̸���? ");
    scanf("%s", p[count].name);
    getchar();
    printf("���̴�? ");
    scanf("%d", &p[count].age);
    printf("������?(����:0, ����:1) ");
    scanf("%d", &p[count].gender);
    getchar();
    printf("mbti��? ");
    scanf("%s", p[count].mbti);
    getchar();
    
    return 1;
}

int readPerson(Person *p, int count) // ��ȣ �Է� �ް� �� ��� ���� ���
{
    int printNum;
    char gender[10];
    printf("���° ����� Ȯ�� �Ͻðڽ��ϱ�? ");
    scanf("%d", &printNum);
    printNum--;
    if (p[count].gender) 
            strcpy(gender, "����");
        else
            strcpy(gender, "����");
    printf("=====================================\n");    
    printf("���: %s\n", p[printNum].name);
    printf("����: %d\n", p[printNum].age);
    printf("����: %s\n", gender);
    printf("mbti: %s\n", p[printNum].mbti);
    printf("=====================================\n");

    return 1;
}


// ������Ʈ �׸��� ���̿� MBTI
int updateData(Person *p, int count) 
{
    int num;
    
    listPerson(p, count);

    printf("������Ʈ�� User ��ȣ (��� : 0) : ");
    scanf("%d", &num);

    if (num == 0) return 0;

    printf("���� : ");
    scanf("%d", &p[num-1].age);
    printf("MBTI : ");
    scanf(" %s", p[num-1].mbti);
    
    printf("=> ������Ʈ �Ϸ�!\n");

    return 1;
}

// ���� ó���� age = -1����
int deletePerson(Person *p, int count)
{
    int num, answer;

    listPerson(p, count);

    printf("������ User ��ȣ (��� : 0) : ");
    scanf("%d", &num);

    if (num == 0) return 0;

    printf("������ �����Ͻðڽ��ϱ�? (���� : 1) ");
    scanf("%d", &answer);

    if (answer == 1) {
        p[num-1].age = -1;
        printf("=> ������\n");
    }

    getchar();
    return 1;
}