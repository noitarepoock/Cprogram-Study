#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// struct student{
//     int num;
//     double grade;
// };

// struct profile{
//     char name[20];
//     int age;
//     double height;
//     char *intro;
// };

// struct profile{
//     int age;
//     double height;
// };

// struct student{
//     struct profile pf;
//     int id;
//     double grade;
// };

// struct student{
//     int id;
//     char name[20];
//     double grade;
// };

// struct vision{
//     double left;
//     double right;
// };

// struct score{
//     int kor;
//     int eng;
//     int math;
// };

// struct cracker{              17-1 Q2
//     int price;
//     int calories;
// };

// struct address{
//     char name[20];
//     int age;
//     char tel[20];
//     char addr[80];
// };

// struct list{
//     int num;
//     struct list *next;
// };

struct profile{             //17-2 Q4(도전 실전 예제)
    int sid;
    char name[20];
    int kor, eng, math;
    double avg;
    char grade;
};

// struct student{
//     int num;
//     double grade;
// };
// typedef struct student Student;
// void print_data(Student *ps){
//     printf("student ID : %d\n", ps->num);
//     printf("grade : %.1lf", ps->grade);
// }

// union student{
//     int num;
//     double grade;
// };

// enum season {SPRING, SUMMER, FALL, WINTER};

// struct vision exchange(struct vision robot){
//     double tmp;

//     tmp = robot.left;
//     robot.left = robot.right;
//     robot.right = tmp;

//     return robot;
// }

// void sorting(struct profile s[5]){           //17-2 Q4(도전 실전 예제)
//     struct profile res[5];
//     double max = s[0].avg;
//     for(int i = 0 ; i < 5; i++){
//         for(int j = i; j < 5; j++){
//             if(s[j].avg >= s[i].avg){
//                 struct profile tmp;
//                 tmp = s[j];
//                 s[j] = s[i];
//                 s[i] = tmp;
//             }
//         }
//     }

// }

int main(){
    // struct student s;

    // s.num = 2;
    // s.grade = 2.7;
    // printf("student id : %d\n", s.num);
    // printf("strdent's grade : %.1lf", s.grade);


    
    // struct profile guql;

    // strcpy(guql.name, "강동협");
    // guql.age = 22;
    // guql.height = 182.8;

    // guql.intro = (char *)malloc(80);
    // printf("introduce myself : ");
    // gets(guql.intro);

    // printf("name : %s\n", guql.name);
    // printf("age : %d\n", guql.age);
    // printf("hegiht : %.1lf\n", guql.height);
    // printf("intro : %s\n", guql.intro);


    
    // struct student guql;

    // guql.pf.age = 22;
    // guql.pf.height = 182.8;
    // guql.id = 315;
    // guql.grade = 4.3;

    // printf("age : %d\n", guql.pf.age);
    // printf("height : %.1lf\n", guql.pf.height);
    // printf("student id : %d\n", guql.id);
    // printf("grade : %.1lf\n", guql.grade);


    
    // struct student s1 = {315, "gildong", 2.4},
    //                 s2 = {316, "soonsin", 3.7},
    //                 s3 = {317, "sejong", 4.4};

    // struct student max;

    // max = s1;
    // if(s2.grade > max.grade) max = s2;
    // if(s3.grade > max.grade) max = s3;

    // printf("sid : %d\n", max.id);
    // printf("name : %s\n", max.name);
    // printf("grade : %.1lf\n", max.grade);



    // struct vision robot;

    // printf("vision : ");
    // scanf("%lf%lf", &robot.left, &robot.right);
    // robot = exchange(robot);
    // printf("changed vision : %.1lf, %.1lf", robot.left, robot.right);



    // struct cracker c;                            //17-1 Q2

    // printf("바사삭의 가격과 열량을 입력하세요 : ");
    // scanf("%d%d", &c.price, &c.calories);
    // printf("바사삭의 가격 : %d원\n", c.price);
    // printf("바사삭의 열량 : %dkcal\n", c.calories);



    // struct score guql = {90, 80, 70};
    // struct score *ps = &guql;

    // printf("korean : %d\n", (*ps).kor);
    // printf("English : %d\n", ps->eng);
    // printf("Math : %d\n", ps->math);



    // struct address list[5] ={
    //     {"홍길동", 23, "111-1111", "울릉도 독도"},     //name , age, tel, addr
    //     {"이순신", 35, "222-2222", "서울 건천동"},
    //     {"장보고",19, "333-3333", "완도 청해진"},
    //     {"유관순", 15, "444-4444", "충남 천안"},
    //     {"안중근", 45, "555-5555", "황해도 해주"}
    // };
    // for(int i = 0 ; i < 5; i++){
    //     printf("%10s%5d%15s%20s\n", list[i].name, list[i].age, list[i].tel, list[i].addr);
    // }



    // struct list a = {10, 0}, b = {20, 0}, c = {30, 0};
    // struct list *head = &a, *current;

    // a.next = &b;
    // b.next = &c;

    // printf("head->num : %d\n", head->num);
    // printf("head->next->num : %d\n", head->next->num);

    // printf("list all : ");
    // current = head;
    // while(current != NULL){
    //     printf("%d ", current -> num);
    //     current = current->next;
    // }
    // printf("\n");



    // union student s1 = {315};

    // printf("sid : %d\n", s1.num);
    // s1.grade = 4.4;
    // printf("grade : %.1lf\n", s1.grade);
    // printf("sid : %d\n", s1.num);



    // enum season ss;
    // char *pc = NULL;

    // ss = SPRING;
    // switch(ss){
    //     case SPRING:
    //         pc = "inline"; break;
    //     case SUMMER:
    //         pc = "swimming"; break;
    //     case FALL:
    //         pc = "trip"; break;
    //     case WINTER:
    //         pc = "skiing"; break;
    // }
    // printf("나의 레저 활동 : %s\n", pc);



    // Student s1 = {315, 4.2};
    // print_data(&s1);



    // struct profile s[5];                 //17-2 Q4(도전 실전 예제)

    // for(int i = 0 ; i < 5; i++){
    //     printf("StudentID : ");
    //     scanf("%d", &s[i].sid);
    //     printf("name : ");
    //     scanf("%s", s[i].name);
    //     printf("kor, eng, math : ");
    //     scanf("%d%d%d", &s[i].kor, &s[i].eng, &s[i].math);
    //     s[i].avg = (s[i].kor + s[i].eng + s[i].math) / 3.0;
    //     if(s[i].avg >= 90.0) s[i].grade = 'A';
    //     else if(s[i].avg >= 80) s[i].grade = 'B';
    //     else if(s[i].avg >= 70) s[i].grade = 'C';
    //     else s[i].grade = 'F';
    // }
    // printf("# Data of before sorting\n");
    // for(int i = 0; i < 5; i++){
    //     printf("%5d%10s%5d%5d%5d%7d   %.1lf%5c\n", s[i].sid, s[i].name, s[i].kor, s[i].eng, s[i].math, (s[i].kor+s[i].eng+s[i].math), s[i].avg, s[i].grade );
    // }

    // sorting(s);
    // printf("# Data of after sorting\n");
    // for(int i = 0; i < 5; i++){
    //     printf("%5d%10s%5d%5d%5d%7d   %.1lf%5c\n", s[i].sid, s[i].name, s[i].kor, s[i].eng, s[i].math, (s[i].kor+s[i].eng+s[i].math), s[i].avg, s[i].grade );
    // }
    

    return 0;
}