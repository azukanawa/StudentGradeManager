#include <stdio.h>
#include <string.h>
#include "../Lib/IO.h"
#include "../Lib/function.h"

ClassInfo classinfo[MAX_CLASS]; // 存储一定数量的行政班信息
int class_num;                  // 班级数量
int main()
{
    TableScore tablescore;
    char filename[100];

    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    ReadStudentInfo(filename, &tablescore);

    Count(&tablescore);

    output(&tablescore);

    return 0;
}