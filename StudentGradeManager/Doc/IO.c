#include <stdio.h>

#include "../Lib/Student.h"
extern ClassInfo classinfo[MAX_CLASS];  // 存储一定数量的行政班信息
extern int class_num;                   // 班级数量
int ReadStudentInfo(
    const char* filename,
    struct TableScore*
        pTableSc)  // const char* filename：教学班数据文件名；struct TableScore
                   // * pTableSc：待建立的顺序表。
{
  if (filename == NULL || pTableSc == NULL)  // 判断指针是否为空指针
  {
    return FALSE;
  }

  // 打开文件
  FILE* fp = fopen(filename, "r");  // 读文件
  if (fp == NULL)                   // 如果文件打开失败
  {
    perror("文件打开失败\n");
    return FALSE;
  }

  pTableSc->student_count = 0;  // 初始化学生数量

  Student tem_stu;  // 作为临时的变量存储学生数据

  while (fscanf(fp, "%s %s %d %d %d %d", tem_stu.name, tem_stu.student_NO,
                &tem_stu.exp_score, &tem_stu.half_term_score,
                &tem_stu.final_score,
                &tem_stu.program_score) == 6)  // 保证读入六个数据
  {
    tem_stu.total_score =
        (int)(0.2 * tem_stu.exp_score + 0.3 * tem_stu.half_term_score +
              0.3 * tem_stu.final_score + 0.2 * tem_stu.program_score +
              0.5);  // 计算总评成绩

    if (pTableSc->student_count >= 50)  // 如果学生数大于数组上限
    {
      printf("error:学生数超过50\n");
      break;
    }
    pTableSc->students[pTableSc->student_count++] =
        tem_stu;  // 将学生信息计入顺序表中
  }
  fclose(fp);  // 关闭文件
  fp = NULL;   // 避免野指针

  if (pTableSc->student_count == 0)  // 如果学生数为0
  {
    printf("无有效数据\n");
    return FALSE;
  }

  printf("文件输入成功，已成功读取%d名学生数据\n", pTableSc->student_count);
  return TRUE;
}

void output(struct TableScore* pTableSc)  // 输出统计信息
{
  printf("学生信息：\n");
  printf("-----------------------------------------------------\n");
  printf(
      "序 号  姓 名       学 号    班 级   实验成绩  半期成绩  期末成绩  "
      "项目成绩  总成绩\n");
  int index = 0;
  char class_NO[7] = {'\0'};
  for (index = 0; index < pTableSc->student_count; index++) {
    CLASS_CALCULATE(pTableSc->students[index].student_NO, class_NO);
    printf("%3d    %s\t %s  %s    %3d       %3d       %3d       %3d      %3d\n",
           index + 1, pTableSc->students[index].name,
           pTableSc->students[index].student_NO, class_NO,
           pTableSc->students[index].exp_score,
           pTableSc->students[index].half_term_score,
           pTableSc->students[index].final_score,
           pTableSc->students[index].program_score,
           pTableSc->students[index].total_score);
  }

  printf("\n");
  printf("统计信息：\n");
  printf("-----------------------------------------------------\n");
  printf("序 号  班 号   学生人数  平均成绩\n");
  for (index = 0; index < class_num; index++) {
    printf("%3d    %s  %4d       %.1f\n", index + 1, classinfo[index].class_NO,
           classinfo[index].student_num, classinfo[index].ave_score);
  }
}