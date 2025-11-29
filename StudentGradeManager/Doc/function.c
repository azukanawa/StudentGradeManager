#include "../Lib/Student.h"
#include <stdio.h>
extern ClassInfo classinfo[MAX_CLASS];  // 存储一定数量的行政班信息
extern int class_num;                   // 班级数量
void Count(struct TableScore *pTableSc) // 统计各个行政班数据
{

    if (pTableSc == NULL || pTableSc->student_count == 0) // 若空指针或学生数量为0
    {
        printf("error!该文件不存在或其内容为空\n");
        return;
    }

    ClassInfo *ClassP = classinfo; // 记录当前是在统计哪个班的信息

    int index = 0;  // 索引一号
    int index1 = 0; // 索引二号
    int found = 0;  // 该班级是否被记录过

    Student *studentP = &(pTableSc->students[0]); // 记录当前是在统计哪个学生的信息
    for (index = 0; index < MAX_CLASS; index++)   // 初始化
    {
        (ClassP + index)->ave_score = 0;
        (ClassP + index)->class_NO[0] = '\0';
        (ClassP + index)->score_sum = 0;
        (ClassP + index)->student_num = 0;
    }
    class_num = 0;

    for (index = 0; index < pTableSc->student_count; index++) // 每一个学生
    {
        char tem_class_NO[7] = "\0"; // 临时班号
        CLASS_CALCULATE((studentP + index)->student_NO, tem_class_NO);
        for (index1 = 0; index1 < class_num; index1++) // 判断班名是否被记录过
        {
            if (strcmp(tem_class_NO, classinfo[index1].class_NO) == 0) // 被记录过
            {
                classinfo[index1].student_num++;
                classinfo[index1].score_sum += (studentP + index)->total_score;
                found = 1;
                break;
            }
        }
        if (found == 1)
        {
            found = 0;
            continue;
        }
        strcpy(classinfo[class_num].class_NO, tem_class_NO);
        classinfo[class_num].student_num++;
        classinfo[class_num].score_sum += (studentP + index)->total_score;
        class_num++;
        if (class_num > MAX_CLASS)
        {
            printf("error!该文件中行政班数量超过20\n");
            return;
        }
    }

    for (index = 0; index < class_num; index++) // 算平均分
    {
        classinfo[index].ave_score = classinfo[index].score_sum * 1.0 / classinfo[index].student_num;
    }
}
