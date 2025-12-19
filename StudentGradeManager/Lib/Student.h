#ifndef STUDENT_H
#define STUDENT_H
#include <string.h>

#define TRUE 1
#define FALSE 0
#define CLASS_CALCULATE(student_NO, class_NO) \
  do {                                        \
    strncpy(class_NO, student_NO, 6);         \
    class_NO[6] = '\0';                       \
  } while (FALSE)
#define MAX_CLASS 20

typedef struct Student  // 学生信息
{
  char name[20];        // 姓名
  char student_NO[20];  // 学号
  int exp_score;        // 实验成绩
  int half_term_score;  // 半期成绩
  int final_score;      // 期末成绩
  int program_score;    // 项目成绩
  int total_score;      // 总评成绩
} Student;

typedef struct TableScore  // 成绩表
{
  Student students[50];
  int student_count;      // 学生数量
  char teacher_name[50];  // 教学班教师姓名
  char class_NO[20];      // 行政班班号
} TableScore;

typedef struct ClassInfo  // 行政班统计信息
{
  char class_NO[20];  // 行政班班号
  int student_num;    // 学生总人数
  int score_sum;      // 班级分数总和
  float ave_score;    // 班级平均分
} ClassInfo;

#endif