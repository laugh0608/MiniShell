//回顾C语言标准库中的IO接口
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    //fopen, 打开文件
    //w+模式打开文件，每次都会将文件清空，截断TRUNC
    FILE* fp = fopen("test.txt", "w+");//fp就是句柄
    char buf[1024] = "QIDian-test";
    //fwrite写文件
    fwrite(buf, strlen(buf), 1, fp);
    memset(buf, 0, 1024);//将buf清空
    //控制文件指针
    fseek(fp, 0, SEEK_SET);
    //读文件
    int ret = fread(buf, 1, 1024, fp);
    printf("ret = %d\n", ret);
    printf("buf = %s\n", buf);
    fclose(fp);
}