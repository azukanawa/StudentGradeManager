#include <stdio.h>
#include <string.h>

#include "../Lib/IO.h"
#include "../Lib/function.h"

ClassInfo classinfo[MAX_CLASS];  // 存储一定数量的行政班信息
int class_num;                   // 班级数量
int main() {
  TableScore tablescore;
  char filename[100];
  printf("请输入文件名（含拓展名）\n");
  fgets(filename, sizeof(filename), stdin);
  filename[strcspn(filename, "\n")] = '\0';

  if (ReadStudentInfo(filename, &tablescore) != 0) {
    Count(&tablescore);

    output(&tablescore);
  }

  printf("按回车结束程序");
  getchar();
  return 0;
}