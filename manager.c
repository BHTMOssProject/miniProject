#include <stdio.h>
#include "manager.h"

// �޴���
int selectMenu()
{
    int menu;

    printf("\n�ѵ� ģ�� ã�� - ���� ģ���� �Ǿ���!\n");
    printf("=====================================\n");
    printf("0. ����\n");
    printf("1. User ���\n");
    printf("2. Ŀ�´�Ƽ Ȯ��\n");
    printf("3. User ������Ʈ\n");
    printf("4. User ����\n");
    printf("\n=> ������ �޴� : ");
    scanf("%d", &menu);

    return menu;
}