#include <stdio.h>
#include "manager.h"

// 메뉴바
int selectMenu()
{
    int menu;

    printf("\n한동 친구 찾기 - 나의 친구가 되어줘!\n");
    printf("=====================================\n");
    printf("0. 종료\n");
    printf("1. User 등록\n");
    printf("2. 커뮤니티 확인\n");
    printf("3. User 업데이트\n");
    printf("4. User 삭제\n");
    printf("5. 유사도 검색\n");
    printf("6. 메시지 남기기\n");
    printf("7. 메시지 확인\n");
    printf("\n=> 선택할 메뉴 : ");
    scanf("%d", &menu);

    return menu;
}
